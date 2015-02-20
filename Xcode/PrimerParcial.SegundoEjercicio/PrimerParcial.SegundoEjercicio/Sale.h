//
//  Sale.h
//  PrimerParcial.SegundoEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __PrimerParcial_SegundoEjercicio__Sale__
#define __PrimerParcial_SegundoEjercicio__Sale__

#include <stdio.h>
#include "Helper.h"
#include "Vehicle.h"
#include "Customer.h"

class Sale {
private:
    int price;
    Vehicle* vehicle;
    Customer buyer;
public:
    Sale();
    Sale(int newPrice, Vehicle* newVehicle, Customer newBuyer);
    void print();
    bool operator<(Sale & sale);
    bool operator==(Sale & sale);
    Customer getCustomer();
};

#endif /* defined(__PrimerParcial_SegundoEjercicio__Sale__) */
