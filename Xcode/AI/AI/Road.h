//
//  Road.h
//  AI
//
//  Created by Jonathan Ginsburg on 5/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef AI_Road_h
#define AI_Road_h

#include <iostream>
#include "City.h"

class Road{
    
private:
    
    long double length = 0;
    
public:
    
    Road() {}
    Road(long double newLength) {
        setLength(newLength);
    }
    Road(City & origin, City & destination){
        try {
            setLength(origin-destination);
        } catch (const char * exception) {
            throw exception;
        }
    }
    
    long double getLength() const {
        return length;
    }
    
    void setLength(long double newLength){
        length = newLength;
    }
    
    bool operator == (const Road & road) const {
        return getLength() == road.getLength();
    }
    
    friend std::ostream & operator << (std::ostream & os, const Road & road){
        os << road.getLength();
        return os;
    }
    
};

#endif
