//
//  Motorcycle.cpp
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Motorcycle.h"

Motorcycle::Motorcycle(int newCode, std::string newBrand, int newModel, int newMileage, int newCylinderCapacity) : Vehicle(newCode, newBrand, newModel, newMileage), cylinderCapacity(newCylinderCapacity){
}

std::string Motorcycle::details(){
    return "motorcycle of " + brand + " from " + Helper::intToString(model) + " with code " + Helper::intToString(code) + " with mileage " + Helper::intToString(mileage) + " with cylinder capacity " + Helper::intToString(cylinderCapacity);
}