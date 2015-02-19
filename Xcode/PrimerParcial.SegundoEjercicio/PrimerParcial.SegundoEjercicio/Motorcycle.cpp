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