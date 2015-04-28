//
//  main.cpp
//  Graphs
//
//  Created by Jonathan Ginsburg on 4/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Graph.h"
#include "Helper.h"
#include "FileManager.h"

Graph<std::string, int> a;
std::vector<std::string> currentSession;

void parse(std::vector<std::string> args);

std::string buildString(std::vector<std::string> args, int low, int high){
    std::string name = "";
    for (int i = low; i < high; ++i) {
        name.append(args[i]);
        if (i != high-1) {
            name.append(" ");
        }
    }
    return name;
}

std::string buildString(std::vector<std::string> args, int low){
    std::string name = "";
    for (int i = low; i < args.size(); ++i) {
        name.append(args[i]);
        if (i != args.size()-1) {
            name.append(" ");
        }
    }
    return name;
}

void remove(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: remove help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("remove cities (removes all cities and all highways)");
        Helper::print("remove city [City's name] (removes the indicated city)");
        Helper::print("remove current_session (shows all cities)");
        Helper::print("remove road [Road's origin] , [Road's destination] (removes all highways)");
        Helper::print("remove roads (removes all highways)");
    }
    else if (args[1] == "cities"){
        a.clear();
    }
    else if (args[1] == "city"){
        if (args.size() <= 2) {
            Helper::print("Missing data. Please type: remove city [City's name]");
            return;
        }
        a.removeVertex(buildString(args, 2));
    }
    else if (args[1] == "roads"){
        a.disconnectAll();
    }
    else if (args[1] == "road"){
        if (args.size() <= 2) {
            Helper::print("Missing data. Please type: remove road [Road's origin] , [Road's destination]");
            return;
        }
        int comma = -1;
        
        for (int i = 2; i < args.size(); ++i) {
            if (args[i] == ",") {
                comma = i;
            }
        }
        a.removeEdge(a.getEdge(buildString(args, 2, comma), buildString(args, comma + 1)));
    }
    else if (args[1] == "current_session"){
        Helper::print("Current session history commands:");
        for (int i = 0; i < currentSession.size(); ++i) {
            std::cout << "\t" << currentSession[i] << std::endl;
        }
    }
}

void show(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: show help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("current_session (shows all commands in the current session except for save and load)");
        Helper::print("show cities (shows all cities)");
        Helper::print("show roads (shows all highways)");
    }
    else if (args[1] == "cities"){
        Helper::print("Printing all cities:");
        for (int i = 0; i < a.getVertices()->size(); ++i) {
            std::cout << "\t" << i+1 << ") " << *(*a.getVertices())[i]->getInfo() << "." << std::endl;
        }
    }
    else if (args[1] == "roads"){
        Helper::print("Printing all roads:");
        for (int i = 0; i < a.getEdges()->size(); ++i) {
            std::cout << "\t" << i+1 << ") " << *(*a.getEdges())[i] << "." << std::endl;
        }
    }
    else if (args[1] == "current_session"){
        Helper::print("Current session history commands:");
        for (int i = 0; i < currentSession.size(); ++i) {
            std::cout << "\t" << currentSession[i] << std::endl;
        }
    }
}

void add(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: add help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("add city [City's name] (adds a city)");
        Helper::print("add road [Road's longitude] [Road's origin] , [Road's destination] (adds a road)");
    }
    else if (args[1] == "city"){
        if (args.size() == 2) {
            Helper::print("Missing name of the city. Please type: add city [City's name]");
            return;
        }
        try {
            a.addVertex(buildString(args, 2));
        } catch (const char* e) {
            Helper::print(e);
        }
    }
    else if (args[1] == "road"){
        if (args.size() <= 2) {
            Helper::print("Missing data. Please type: add road [Road's longitude] [Road's origin] , [Road's destination]");
            return;
        }
        int comma = -1;
        
        for (int i = 2; i < args.size(); ++i) {
            if (args[i] == ",") {
                comma = i;
            }
        }
        
        if (!Helper::stringIsNumber(args[2])) {
            Helper::print("[Road's longitude] must be a number...");
            return;
        }
        
        try {
            a.addEdge(atoi(args[2].c_str()), *a.getVertex(buildString(args, 3, comma))->getInfo(), *a.getVertex(buildString(args, comma + 1))->getInfo());
        } catch (const char* e) {
            Helper::print(e);
        }
    }
}

void save(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: save help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("save [Session name] (saves current session)");
    }
    else{
        FileManager::saveSession(buildString(args, 1), currentSession);
    }
}

void load(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: load help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("load [Session name] (deletes current session and loads a new one)");
    }
    else{
        currentSession = FileManager::loadSession(buildString(args, 1));
        for (int i = 0; i < currentSession.size(); ++i) {
            std::vector<std::string> NewArgs = Helper::split(currentSession[i], ' ');
            std::cout << buildString(args, 1) << ">>> " << currentSession[i] << std::endl;
            parse(NewArgs);
        }
    }
}

void parse(std::vector<std::string> args){
    
    if (args[0] == "help") {
        Helper::print("add (adds information)");
        Helper::print("load (loads a session of commands)");
        Helper::print("quit");
        Helper::print("remove (removes information)");
        Helper::print("save (saves current session of commands)");
        Helper::print("show (displays information)");
    }
    else if (args[0] == "show"){
        show(args);
    }
    else if (args[0] == "add"){
        add(args);
    }
    else if (args[0] == "save"){
        save(args);
    }
    else if (args[0] == "load"){
        load(args);
    }
    else if (args[0] == "remove"){
        remove(args);
    }
}

bool prompt(){
    std::string input = Helper::readLine(">>> ");
    std::vector<std::string> args = Helper::split(input, ' ');
    if (args[0] == "save" || args[0] == "load") {
        parse(args);
        return true;
    }
    else currentSession.push_back(input);
    if (args[0] == "quit") return false;
    else {
        parse(args);
        return true;
    }
};

int main(int argc, const char * argv[]) {
    Helper::print("Welcome to the road helper V 1.0 by Jonathan Ginsburg and Santiago Rodriguez.");
    Helper::print("Type help for all commands available.");
    while (prompt()) {}
    return 0;
}
