//
//  Date.h
//  Tarea5.BinaryTrees.E4
//
//  Created by Jonathan Ginsburg on 4/21/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea5_BinaryTrees_E4__Date__
#define __Tarea5_BinaryTrees_E4__Date__

#include "Helper.h"

class Date{

private:
    int day = 0;
    int month = 0;
    int year = 0;
    
public:
    //Constructors
    Date() {};
    Date(int & newDay, int & newMonth, int & newYear) : day(newDay), month(newMonth), year(newYear) {};
    
    //Getters
    int getDay() const {return day;};
    int getMonth() const {return month;};
    int getYear() const {return year;};
    
    //Setters
    void setDay(int & newDay) {day = newDay;};
    void setMonth(int & newMonth) {month = newMonth;};
    void setYear(int & newYear) {year = newYear;};
    
    //Validations
    bool isEmpty() const {return day == 0 || month == 0 || year == 0;};
    
    //Comparisons
    bool operator == (const Date & otherDate) const;
    bool operator > (const Date & otherDate) const;
    bool operator < (const Date & otherDate) const;
};

std::ostream & operator << (std::ostream & os, const Date & date){
    os << Helper::intToString(date.getDay()) << "/" << Helper::intToString(date.getMonth()) << "/" << Helper::intToString(date.getYear());
    return os;
}



#endif /* defined(__Tarea5_BinaryTrees_E4__Date__) */
