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

int main(int argc, const char * argv[]) {
    if (argc == 1 || argc >= 3) {
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
    }
    return 0;
}
