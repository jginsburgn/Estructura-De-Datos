//
//  main.cpp
//  Translator
//
//  Created by Jonathan Ginsburg on 5/3/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "FileManager.h"
#include "Helper.h"

void FilterByCountry(){
    std::vector<std::string> file = FileManager::loadFile(Helper::readLine("Enter the name of the file to load:\n"));
    std::vector<std::string> newFile;
    std::string country = Helper::readLine("Enter the acronym of the country in lowercase (e.g. us): \n");
    for (int i = 0; i < file.size(); ++i) {
        std::vector<std::string> separated = Helper::split(file[i], ',');
        if (separated[0] == country) {
            newFile.push_back(file[i]);
        }
    }
    FileManager::saveFile(Helper::readLine("Enter the name of the new file:\n"), newFile);
}

void FilterByRegion(){
    std::vector<std::string> file = FileManager::loadFile(Helper::readLine("Enter the name of the file to load:\n"));
    std::vector<std::string> newFile;
    std::string region = Helper::readLine("Enter the acronym of the state or region in uppercase (e.g. TX): \n");
    for (int i = 0; i < file.size(); ++i) {
        std::vector<std::string> separated = Helper::split(file[i], ',');
        if (separated[3] == region) {
            newFile.push_back(file[i]);
        }
    }
    FileManager::saveFile(Helper::readLine("Enter the name of the new file:\n"), newFile);
}

void FilterByPopulation(){
    std::vector<std::string> file = FileManager::loadFile(Helper::readLine("Enter the name of the file to load:\n"));
    std::vector<std::string> newFile;
    float minimum = Helper::stringToFloat(Helper::readLine("Enter minimum population (e.g. 1000000): \n"));
    for (int i = 0; i < file.size(); ++i) {
        std::vector<std::string> separated = Helper::split(file[i], ',');
        try {
            float population = Helper::stringToFloat(separated[4]);
            if (population > minimum) {
                newFile.push_back(file[i]);
            }
        } catch (const char * exception) {}
    }
    FileManager::saveFile(Helper::readLine("Enter the name of the new file:\n"), newFile);
}

void makeReadable(){
    std::vector<std::string> file = FileManager::loadFile(Helper::readLine("Enter the name of the file to load:\n"));
    std::vector<std::string> newFile;
    for (int i = 0; i < file.size(); ++i) {
        std::vector<std::string> separated = Helper::split(file[i], ',');
        std::string command = "add city ";
        command.append(separated[1]);
        command.append(" ");
        command.append(separated[5]);
        command.append(" , ");
        command.append(separated[6]);
        newFile.push_back(command);
    }
    FileManager::saveFile(Helper::readLine("Enter the name of the new file:\n"), newFile);
}

void TranslateGeogebra(){
    std::vector<std::string> file = FileManager::loadFile(Helper::readLine("Enter the name of the file to read:\n"));
    std::vector<std::string> newFile;
    for (int i = 0; i < file.size(); ++i) {
        if (Helper::stringStartsWithSequence(file[i], "<element")) {
            std::vector<std::string> elementLine = Helper::split(file[i], ' ');
            if (elementLine[1] == "type=\"point\"") {
                std::string name = Helper::split(elementLine[2], '"')[1];
                int coordLinePosition = -1;
                for (int j = i + 1; j < file.size(); ++j) {
                    if (Helper::stringStartsWithSequence(file[j], "\t<coords")) {
                        coordLinePosition = j;
                        break;
                    }
                }
                i = coordLinePosition;
                std::string x = Helper::split(file[coordLinePosition], ' ')[1];
                x = Helper::split(x, '"')[1];
                std::string y = Helper::split(file[coordLinePosition], ' ')[2];
                y = Helper::split(y, '"')[1];
                std::string command = "add city ";
                command.append(name);
                command.append(" ");
                command.append(y);
                command.append(" , ");
                command.append(x);
                newFile.push_back(command);
            }
        }
    }
    for (int i = 0; i < file.size(); ++i) {
        if (Helper::stringStartsWithSequence(file[i], "<command")) {
            std::vector<std::string> elementLine = Helper::split(file[i], ' ');
            if (elementLine[1] == "name=\"Vector\">") {
                int endPointsPosition = -1;
                for (int j = i + 1; j < file.size(); ++j) {
                    if (Helper::stringStartsWithSequence(file[j], "\t<input")) {
                        endPointsPosition = j;
                        break;
                    }
                }
                i = endPointsPosition;
                std::string from = Helper::split(file[endPointsPosition], ' ')[1];
                from = Helper::split(from, '"')[1];
                std::string to = Helper::split(file[endPointsPosition], ' ')[2];
                to = Helper::split(to, '"')[1];
                std::string command = "add road ";
                command.append(from);
                command.append(" , ");
                command.append(to);
                newFile.push_back(command);
            }
        }
    }
    for (int i = 0; i < file.size(); ++i) {
        if (Helper::stringStartsWithSequence(file[i], "<command")) {
            std::vector<std::string> elementLine = Helper::split(file[i], ' ');
            if (elementLine[1] == "name=\"Segment\">") {
                int endPointsPosition = -1;
                for (int j = i + 1; j < file.size(); ++j) {
                    if (Helper::stringStartsWithSequence(file[j], "\t<input")) {
                        endPointsPosition = j;
                        break;
                    }
                }
                i = endPointsPosition;
                std::string from = Helper::split(file[endPointsPosition], ' ')[1];
                from = Helper::split(from, '"')[1];
                std::string to = Helper::split(file[endPointsPosition], ' ')[2];
                to = Helper::split(to, '"')[1];
                std::string command = "add roadsym ";
                command.append(from);
                command.append(" , ");
                command.append(to);
                newFile.push_back(command);
            }
        }
    }
    FileManager::saveFile(Helper::readLine("Enter the name of the new readable file:\n"), newFile);
}

int main(int argc, const char * argv[]) {
    Helper::print("Welcome to the translator tool for the AI program.");
    if (argc == 1 || argc >= 3) {
        Helper::print("Available translations:");
        Helper::print("\tcountry (takes a file with the format of worldcitiespop.txt and outputs a file filtered by a given country)");
        Helper::print("\tpopulation (takes a file with the format of worldcitiespop.txt and outputs a file filtered by a given minimum population)");
        Helper::print("\tregion (takes a file with the format of worldcitiespop.txt and outputs a file filtered by a given region)");
        Helper::print("\tmakereadable (takes a file with the format of worldcitiespop.txt and outputs a file readable by the AI program)");
        Helper::print("\tgeogebra (takes a file with the format of geogebra.xml and outputs a file readable by the AI program)");
        Helper::print("\tcountry (takes a file with the format of worldcitiespop.txt and outputs a file filtered by a given country)");
        Helper::print("To use translator please call with an argument (e.g. Translator geogebra)");
        return 0;
    }
    else{
        if (strcmp(argv[1], "country") == 0) {
            FilterByCountry();
        }
        else if (strcmp(argv[1], "population") == 0){
            FilterByPopulation();
        }
        else if (strcmp(argv[1], "region") == 0){
            FilterByRegion();
        }
        else if (strcmp(argv[1], "makereadable") == 0){
            makeReadable();
        }
        else if (strcmp(argv[1], "geogebra") == 0){
            TranslateGeogebra();
        }
    }
    
    return 0;
}
