//
//  Person.cpp
//  Tarea3.ListasEnlazadas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/3/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Person.h"

Person::Person(){
    Date newDateOfBirth;
    newDateOfBirth.day = 0;
    newDateOfBirth.month = 0;
    newDateOfBirth.year = 0;
    dateOfBirth = newDateOfBirth;
}

Person::Person(std::string newFistName, std::string newLastName, std::string newLastLastName, int newAge, Date newDateOfBirth) : firstName(newFistName), lastName(newLastName), lastLastName(newLastLastName), age(newAge), dateOfBirth(newDateOfBirth){}

bool Person::operator < (const Person person) const{
    if (lastName < person.getLastName()) {
        return true;
    }
    else{
        if (lastName == person.getLastName()){
            if (lastLastName < person.getLastLastName()) {
                return true;
            }
            else{
                if (lastLastName == person.getLastLastName()) {
                    if (firstName < person.getFirstName()) {
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

bool Person::operator > (const Person person) const{
    if (lastName > person.getLastName()) {
        return true;
    }
    else{
        if (lastName == person.getLastName()){
            if (lastLastName > person.getLastLastName()) {
                return true;
            }
            else{
                if (lastLastName == person.getLastLastName()) {
                    if (firstName > person.getFirstName()) {
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

bool Person::operator == (const Person person) const{
    return firstName == person.getFirstName() && lastName == person.getLastName() && lastLastName == person.getLastLastName() && age == person.getAge() && dateOfBirth.day == person.getDateOfBirth().day && dateOfBirth.month == person.getDateOfBirth().month && dateOfBirth.year == person.getDateOfBirth().year;
}

std::ostream & operator<<(std::ostream & os, const Person person){
    os << person.lastName << " " << person.lastLastName << ", " << person.firstName << "; age: " << person.age << "; born on: " << person.dateOfBirth.day << "/" << person.dateOfBirth.month << "/" << person.dateOfBirth.year << ".";
    return os;
}
