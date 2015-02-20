//
//  Customer.h
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __PrimerParcial_SegundoEjercicio__Customer__
#define __PrimerParcial_SegundoEjercicio__Customer__

#include <stdio.h>
#include "Helper.h"
#include <iostream>

class Customer {
private:
    std::string firstName;
    std::string lastName;
    int idNumber;
public:
    Customer();
    Customer(std::string newFirstName, std::string newLastName, int newIdNumber);
    void print();
    int getIdNumber();
    std::string details();
    bool operator==(Customer & customer);
};

#endif /* defined(__PrimerParcial_SegundoEjercicio__Customer__) */
