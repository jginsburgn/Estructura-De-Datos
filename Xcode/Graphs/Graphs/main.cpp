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

Graph<std::string, int> a;

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

void remove();

void show(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: show help (for displaying options)");
    }
    else if (args[1] == "help") {
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
}

void add(std::vector<std::string> args){
    if (args.size() == 1) {
        Helper::print("Incomplete command.");
        Helper::print("Type: add help (for displaying options)");
    }
    else if (args[1] == "help") {
        Helper::print("add city (adds a city)");
        Helper::print("add road (adds a road)");
    }
    else if (args[1] == "city"){
        if (args.size() == 2) {
            Helper::print("Missing name of the city. Please type add city [city's name]");
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
            Helper::print("Missing data. Please type: add road [road's longitude] [road's origin] , [road's destination]");
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

void parse(std::vector<std::string> args){
    if (args[0] == "help") {
        Helper::print("add (adds information)");
        Helper::print("show (displays information)");
    }
    else if (args[0] == "show"){
        show(args);
    }
    else if (args[0] == "add"){
        add(args);
    }
}

bool prompt(){
    std::string input = Helper::readLine(">>> ");
    std::vector<std::string> args = Helper::split(input, ' ');
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
