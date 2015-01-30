//
//  Car.h
//  EjerciciosDeBusqueda.Ejercicio3
//
//  Created by Jonathan Ginsburg on 1/29/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __EjerciciosDeBusqueda_Ejercicio3__Car__
#define __EjerciciosDeBusqueda_Ejercicio3__Car__

#include <stdio.h>
#include <iostream>
#include "Service.h"
#include <string>

#define maxServicesPerCar 10

class Car{
private:
    int lastServiceIndex = 0;
public:
    std::string plate;
    Service* services;
    
    Car();
    Car(std::string newPlate);
    bool addService(Service newService);
    bool operator==(Car carToCompare);
    friend std::ostream& operator<<(std::ostream &outputStream, Car car);
    void printServices();
    int totalMaintenanceCosts();
    void printDetails();
};

#endif /* defined(__EjerciciosDeBusqueda_Ejercicio3__Car__) */
