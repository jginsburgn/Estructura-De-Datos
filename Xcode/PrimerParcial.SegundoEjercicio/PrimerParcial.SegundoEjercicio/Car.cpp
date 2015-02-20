//
//  Car.cpp
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Car.h"

Car::Car(int newCode, std::string newBrand, int newModel, int newMileage): Vehicle(newCode, newBrand, newModel, newMileage){
}

std::string Car::details(){
    return "car of " + brand + " from " + Helper::intToString(model) + " with code " + Helper::intToString(code) + " with mileage " + Helper::intToString(mileage);
}