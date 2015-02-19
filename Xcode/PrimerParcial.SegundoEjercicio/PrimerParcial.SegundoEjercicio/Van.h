//
//  Van.h
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __PrimerParcial_SegundoEjercicio__Van__
#define __PrimerParcial_SegundoEjercicio__Van__

#include <stdio.h>
#include "Vehicle.h"

class Van : Vehicle{
protected:
    std::string traction;
public:
    Van(int newCode, std::string newBrand, int newModel, int newMileage, std::string newTraction);
};

#endif /* defined(__PrimerParcial_SegundoEjercicio__Van__) */
