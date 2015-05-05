//
//  FileManager.h
//  Graphs
//
//  Created by Jonathan Ginsburg on 4/27/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Graphs_FileManager_h
#define Graphs_FileManager_h

#include "Helper.h"
#include <fstream>
#include <vector>

class FileManager{
public:
    
    static std::string readFile(std::string fileName){
        std::string returner = "";
        std::string line;
        std::fstream document;
        document.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
        document.seekg(0);
        if (document.is_open())
        {
            while ( getline (document,line) )
            {
                returner.append(line);
            }
            document.close();
        }
        return returner;
    }
    
    static std::vector<std::string> loadFile(std::string fileName) {
        std::vector<std::string> returner;
        std::string line;
        std::fstream document;
        document.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
        document.seekg(0);
        if (document.is_open())
        {
            while ( getline (document,line) )
            {
                returner.push_back(line);
            }
            document.close();
        }
        return returner;
    };
    
    static bool saveFile(std::string fileName, std::vector<std::string> file) {
        std::fstream document;
        document.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app);
        
        document.seekp(0);
        for (int i = 0; i < file.size(); ++i) {
            std::string line = file[i];
            document << line << std::endl;
        }
        document.flush();
        
        return true;
    };
    
};

#endif
