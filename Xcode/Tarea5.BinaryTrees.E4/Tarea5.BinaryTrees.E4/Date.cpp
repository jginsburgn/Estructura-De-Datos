//
//  Date.cpp
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Date.h"

bool Date::operator == (const Date & otherDate) const{
    if (otherDate.isEmpty() || this->isEmpty()) {
        return false;
    }
    return day==otherDate.getDay() && month == otherDate.getMonth() && year == otherDate.getYear();
}

bool Date::operator > (const Date & otherDate) const{
    if (otherDate.isEmpty() || this->isEmpty() || otherDate == *this) {
        return false;
    }
    
    if (year > otherDate.getYear()) {
        return true;
    }
    else{
        if (year == otherDate.getYear()) {
            if (month > otherDate.getMonth()) {
                return true;
            }
            else{
                if (month == otherDate.getMonth()) {
                    if (day > otherDate.getDay()) {
                        return true;
                    }
                    else return false;
                }
                else return false;
            }
        }
        else return false;
    }
}

bool Date::operator < (const Date & otherDate) const{
    if (otherDate.isEmpty() || this->isEmpty() || *this == otherDate || *this > otherDate) {
        return false;
    }
    return true;
}

std::ostream & operator<<(std::ostream & os, const Date & date){
    os << Helper::intToString(date.getDay()) << "/" << Helper::intToString(date.getMonth()) << "/" << Helper::intToString(date.getYear());
    return os;
}