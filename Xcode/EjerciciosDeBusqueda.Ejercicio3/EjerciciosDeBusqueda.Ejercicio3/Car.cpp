//
//  Car.cpp
//  EjerciciosDeBusqueda.Ejercicio3
//
//  Created by Jonathan Ginsburg on 1/29/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Car.h"
#include "Helper.h"

Car::Car(): plate("000000"){}

Car::Car(std::string newPlate): plate(newPlate){
    services = new Service[maxServicesPerCar];
}

bool Car::addService(Service newService){
    if (lastServiceIndex + 1 < maxServicesPerCar){
        services[lastServiceIndex++] = newService;
        return true;
    }
    return false;
}

bool Car::operator==(Car carToCompare){
    return this->plate==carToCompare.plate;
}

std::ostream& operator<<(std::ostream& outputStream, Car car){
    outputStream << "Car with plates: " << car.plate;
    return outputStream;
}

void Car::printServices(){
    if (lastServiceIndex == 0) return Helper::print("No services have been made to this car");
    for (int i = 0; i < lastServiceIndex; ++i) {
        std::cout << services[i] << std::endl;
    }
}

int Car::totalMaintenanceCosts(){
    int total = 0;
    for (int i = 0; i < lastServiceIndex; ++i) {
        total += services[i].price;
    }
    return total;
}

void Car::printDetails(){
    std::cout << *this << std::endl;
    Helper::print("It's services are as follows:");
    printServices();
    Helper::print("The total fees for maintenance of this car are: $" + Helper::intToString(this->totalMaintenanceCosts()));
}