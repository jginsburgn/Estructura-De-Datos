//
//  City.h
//  AI
//
//  Created by Jonathan Ginsburg on 5/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef AI_City_h
#define AI_City_h

#include <string>
#include <iostream>

class City {
    
private:
    
    std::string name =  "No name";
    float latitude =  0;
    float longitude = 0;
    bool coordinatesSet = false;
    
public:
    
    City() {}
    City(std::string newName){
        setName(newName);
    }
    City(std::string newName, float newLatitude, float newLongitude){
        setName(newName);
        setCoordinates(newLatitude, newLongitude);
    }
    
    std::string getName() const {
        return name;
    }
    
    float getLatitude() const {
        if (coordinatesSet) {
            return latitude;
        }
        throw "Coordinates of city are not set...";
    }
    
    float getLongitude() const {
        if (coordinatesSet) {
            return longitude;
        }
        throw "Coordinates of city are not set...";
    }
    
    void setName(std::string newName) {
        name = newName;
    }
    
    void setCoordinates(float newLatitude, float newLongitude){
        coordinatesSet = true;
        latitude = newLatitude;
        longitude = newLongitude;
    }
    
    bool operator == (const City & city) const {
        bool retVal = getName() == city.getName();
        return retVal;
    }
    
    friend std::ostream & operator << (std::ostream & os, const City & city){
        os << city.getName();
        try {
            os << " (Lat: " << city.getLatitude() << ", Lon: " << city.getLongitude() << ")";
        } catch (const char * exception) {
            os << ". Unknown position";
        }
        return os;
    }
    
};


#endif
