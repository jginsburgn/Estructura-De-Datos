//
//  main.cpp
//  EjerciciosEstructurasDeDatos.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/23/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Person.h"
#include "Helper.h"

void addPerson(Queue<Person> * persons);
void removePerson(Queue<Person> * persons);
void estimateTimes(Queue<Person> * persons);

int main(int argc, const char * argv[]) {
    
    Queue<Person> * persons = new Queue<Person>();
    
    std::string * menu = new std::string[3];
    menu[0] = "Add person";
    menu[1] = "Remove person";
    menu[2] = "Estimate Times";
    
    switch (Helper::menu("main", menu, 3)) {
        case 1:
            addPerson(persons);
            break;
        case 2:
            removePerson(persons);
            break;
        case 3:
            estimateTimes(persons);
            break;
            
        default:
            break;
    }
    
    return 0;
}

void addPerson(Queue<Person> * persons){
    
}
void removePerson(Queue<Person> * persons){
    
}
void estimateTimes(Queue<Person> * persons){
    
}