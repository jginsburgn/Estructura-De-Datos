//
//  Sale.cpp
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Sale.h"

Sale::Sale(){
    price =  0;
    vehicle = nullptr;
    buyer = Customer("", "", 0);
}

Sale::Sale(int newPrice, Vehicle* newVehicle, Customer newBuyer) : vehicle(newVehicle), price(newPrice), buyer(newBuyer){
}

void Sale::print(){
    Helper::print("Sale of " + vehicle->details() + " to " + buyer.details() + "; for " + Helper::intToString(price) + " dollars.");
}

bool Sale::operator<(Sale &sale){
    return this->price < sale.price;
}

bool Sale::operator==(Sale &sale){
    return this->price == sale.price;
}

Customer Sale::getCustomer(){
    return buyer;
}