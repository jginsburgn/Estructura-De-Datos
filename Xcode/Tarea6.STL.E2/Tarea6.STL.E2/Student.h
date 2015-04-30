//
//  Student.h
//  Tarea6.STL.E2
//
//  Created by Jonathan Ginsburg on 4/29/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Tarea6_STL_E2_Student_h
#define Tarea6_STL_E2_Student_h

#include <string>
#include <iostream>

class Student {
    
    std::string name;
    std::string lastName;
    int age;
    
public:
    
    Student() {}
    
    Student(std::string newName, std::string newLastName, int newAge) {
        setName(newName);
        setLastName(newLastName);
        setAge(newAge);
    }
    
    std::string getName() const {
        return name;
    }
    
    std::string getLastName() const {
        return lastName;
    }
    
    int getAge() const {
        return age;
    }
    
    void setName(std::string newName) {
        name = newName;
    }
    
    void setLastName(std::string newLastName) {
        lastName = newLastName;
    }
    
    void setAge(int newAge) {
        age = newAge;
    }
    
    bool operator == (const Student & student){
        return name == student.getName() && lastName == student.getLastName();
    }
    
    friend std::ostream & operator << (std::ostream & os, const Student & student){
        os << "Student: " << student.getLastName() << ", " << student.getName() << "; of age: " << student.getAge();
        return os;
    }
};

#endif
