//
//  Person.h
//  EjerciciosEstructurasDeDatos.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/23/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __EjerciciosEstructurasDeDatos_Ejercicio3__Person__
#define __EjerciciosEstructurasDeDatos_Ejercicio3__Person__

enum transactionType {
    withdrawal = 8, deposit = 4, consultation = 7, update = 10, payments = 4
};


#include <stdio.h>
#include <iostream>
#include "Queue.h"

class Person{
    std::string name = "";
    Queue<transactionType> * transactions;
public:
    Person(std::string newName, Queue<transactionType> * newTransactions) : name(newName), transactions(newTransactions) {};
    double timeOfTransactions();
    std::string getName();
    bool operator == (Person & person);
    bool operator != (Person & person);
};

#endif /* defined(__EjerciciosEstructurasDeDatos_Ejercicio3__Person__) */
