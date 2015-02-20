//
//  Motorcycle.h
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __PrimerParcial_SegundoEjercicio__Motorcycle__
#define __PrimerParcial_SegundoEjercicio__Motorcycle__

#include <stdio.h>
#include "Vehicle.h"
#include "Helper.h"

class Motorcycle : public Vehicle{
protected:
    int cylinderCapacity;
public:
    Motorcycle(int newCode, std::string newBrand, int newModel, int newMileage, int newCylinderCapacity);
    virtual std::string details();
};

#endif /* defined(__PrimerParcial_SegundoEjercicio__Motorcycle__) */
