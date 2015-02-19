//
//  Car.h
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __PrimerParcial_SegundoEjercicio__Car__
#define __PrimerParcial_SegundoEjercicio__Car__

#include <stdio.h>
#include "Vehicle.h"

class Car : public Vehicle{
public:
    Car(int newCode, std::string newBrand, int newModel, int newMileage);
};

#endif /* defined(__PrimerParcial_SegundoEjercicio__Car__) */
