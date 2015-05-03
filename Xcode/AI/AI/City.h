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
    long double latitude =  0;
    long double longitude = 0;
    bool coordinatesSet = false;
    
public:
    
    City() {}
    City(std::string newName){
        setName(newName);
    }
    City(std::string newName, long double newLatitude, long double newLongitude){
        setName(newName);
        setCoordinates(newLatitude, newLongitude);
    }
    
    std::string getName() const {
        return name;
    }
    
    long double getLatitude() const {
        if (coordinatesSet) {
            return latitude;
        }
        throw "Coordinates of city are not set...";
    }
    
    long double getLongitude() const {
        if (coordinatesSet) {
            return longitude;
        }
        throw "Coordinates of city are not set...";
    }
    
    void setName(std::string newName) {
        name = newName;
    }
    
    void setCoordinates(long double newLatitude, long double newLongitude){
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
            os << " (Lat: " << std::to_string(city.getLatitude()) << ", Lon: " << std::to_string(city.getLongitude()) << ")";
        } catch (const char * exception) {
            os << ". Unknown position";
        }
        return os;
    }
    
};


#endif
