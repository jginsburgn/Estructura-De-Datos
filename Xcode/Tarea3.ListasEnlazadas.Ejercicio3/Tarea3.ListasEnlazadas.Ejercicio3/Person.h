//
//  Person.h
//  Tarea3.ListasEnlazadas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/3/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea3_ListasEnlazadas_Ejercicio3__Person__
#define __Tarea3_ListasEnlazadas_Ejercicio3__Person__

#include <stdio.h>

#include "Helper.h"

struct Date{
    int day;
    int month;
    int year;
};

class Person{
    std::string firstName = "";
    std::string lastName = "";
    std::string lastLastName = "";
    int age = 0;
    Date dateOfBirth;
public:
    std::string getFirstName() const {return firstName;};
    std::string getLastName() const {return lastName;};
    std::string getLastLastName() const {return lastLastName;};
    int getAge() const {return age;};
    Date getDateOfBirth() const {return dateOfBirth;};
    
    void setFirstName(std::string newFirstName) {firstName = newFirstName;};
    void setLastName(std::string newLastName) {lastName = newLastName;};
    void setLastLastName(std::string newLastLastName) {lastLastName = newLastLastName;};
    void setAge(int newAge) {age = newAge;};
    void setDateOfBirth(Date newDateOfBirth) {dateOfBirth = newDateOfBirth;};
    
    Person();
    Person(std::string newFistName, std::string newLastName, std::string newLastLastName, int newAge, Date newDateOfBirth);
    friend std::ostream & operator << (std::ostream & os, const Person person);
    bool operator < (const Person person) const;
    bool operator > (const Person person) const;
    bool operator == (const Person person) const;
};


#endif /* defined(__Tarea3_ListasEnlazadas_Ejercicio3__Person__) */
