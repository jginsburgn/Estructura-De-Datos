//
//  Van.cpp
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Van.h"

Van::Van(int newCode, std::string newBrand, int newModel, int newMileage, std::string newTraction) : Vehicle(newCode, newBrand, newModel, newMileage), traction(newTraction){}