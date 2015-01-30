//
//  main.cpp
//  EjerciciosDeBusqueda.Ejercicio3
//
//  Created by Jonathan Ginsburg on 1/29/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <string>
#include <iostream>
#include "Car.h"
#include "Service.h"
#include "Helper.h"


const int maxNumberOfCars = 10;
int lastAddedCar =  0;
Car cars[maxNumberOfCars];

bool addNewCar(Car newCar);
void printCars();
void populateCars();
int searchCar(std::string plates);


int main() {

    populateCars();
    printCars();
    std::string platesToSearch = Helper::read<std::string>("Plates to search: ");
    int index = searchCar(platesToSearch);
    if (index == -1) {
        Helper::print("Car not in inventory");
    }
    else cars[index].printDetails();
    // insert code here...
    return 0;
}

int searchCar(std::string plates){
    for (int i = 0; i < lastAddedCar; ++i) {
        if (cars[i].plate == plates) return i;
    }
    return -1;
}

void populateCars(){
    for (int i = 0; i < maxNumberOfCars; ++i) {
        std::string plate = Helper::read<std::string>("Type the plate number of car number " +  Helper::intToString(i+1));
        if (!addNewCar(Car(plate))){
            --i;
            Helper::print("Car was not added, because plate is duplicated. Try again.");
        }
    }
}

void printCars(){
    for (int i = 0; i< maxNumberOfCars; ++i) {
        std::cout << cars[i] << std::endl;
    }
}

bool addNewCar(Car newCar){
    for (int i =  0; i < lastAddedCar; ++i) {
        if (cars[i]==newCar) {
            return false;
        }
    }
    cars[lastAddedCar++] = newCar;
    return true;
}
