//
//  Path.h
//  AI
//
//  Created by Jonathan Ginsburg on 5/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef AI_Path_h
#define AI_Path_h

#include "Edge.h"
#include "City.h"
#include "Road.h"
#include <vector>
#include <iostream>
#include <string>

class Path{
    
private:
    
    std::vector<Edge<City, Road> *> path;
    
public:
    
    Path() {}
    
    void addStep(Edge<City, Road> * newStep){
        path.push_back(newStep);
    }
    
    friend std::ostream & operator << (std::ostream & os, const Path & p){
        for (int i = 0; i < p.path.size(); ++i) {
            os << "\t" << *p.path[i] << std::endl;
        }
        return os;
    }
    
};

#endif
