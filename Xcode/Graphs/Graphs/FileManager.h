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
    static std::vector<std::string> loadSession(std::string sessionName) {
        std::vector<std::string> returner;
        std::string line;
        std::fstream document;
        document.open(sessionName, std::fstream::in | std::fstream::out | std::fstream::app);
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
    
    static bool saveSession(std::string sessionName, std::vector<std::string> commands) {
        std::fstream document;
        document.open(sessionName, std::fstream::in | std::fstream::out | std::fstream::app);
        
        document.seekp(0);
        for (int i = 0; i < commands.size(); ++i) {
            std::string line = commands[i];
            document << line << std::endl;
        }
        document.flush();
        
        return true;
    };
    
};

#endif
