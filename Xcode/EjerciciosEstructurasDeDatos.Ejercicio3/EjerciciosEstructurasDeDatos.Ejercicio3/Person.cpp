//
//  Person.cpp
//  EjerciciosEstructurasDeDatos.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/23/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Person.h"

double Person::timeOfTransactions(){
    double totalTime = 0;
    for (int i = 0; i < transactions->size(); ++i) {
        Node<transactionType> * tmp = transactions->dequeue();
        totalTime += tmp->getInfo();
        transactions->enqueue(tmp);
    }
    return totalTime;
}

std::string Person::getName(){
    return name;
}

bool Person::operator == (Person & person){
    return name == person.getName();
}
bool Person::operator != (Person & person){
    return name != person.getName();
}