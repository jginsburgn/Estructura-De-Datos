//
//  Customer.cpp
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Customer.h"

Customer::Customer(){
    firstName = "";
    lastName = "";
    idNumber = 0;
}

Customer::Customer(std::string newFirstName, std::string newLastName, int newIdNumber) : firstName(newFirstName), lastName(newLastName), idNumber(newIdNumber){
}

void Customer::print(){
    Helper::print("Name: " + firstName + ", Last Name: " + lastName + " ID: " + Helper::intToString(idNumber) + ".");
}

int Customer::getIdNumber(){
    return idNumber;
}

std::string Customer::details(){
    return firstName + " " + lastName + ", with ID number: " + Helper::intToString(idNumber);
}

bool Customer::operator==(Customer &customer){
    return this->firstName == customer.firstName && this->lastName == customer.lastName && this->idNumber == customer.idNumber;
}