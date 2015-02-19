//
//  Vehicle.h
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __PrimerParcial_SegundoEjercicio__Vehicle__
#define __PrimerParcial_SegundoEjercicio__Vehicle__

#include <stdio.h>
#include <iostream>

class Vehicle {
protected:
    int code;
    std::string brand;
    int model;
    int mileage;
public:
    Vehicle(int newCode, std::string newBrand, int newModel, int newMileage);
};

#endif /* defined(__PrimerParcial_SegundoEjercicio__Vehicle__) */
