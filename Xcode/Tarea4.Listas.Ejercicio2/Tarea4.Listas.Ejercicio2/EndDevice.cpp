//
//  EndDevice.cpp
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "EndDevice.h"

void EndDevice::deliverToken(Token token){
    
}

void EndDevice::openConsole(){
    
}

bool EndDevice::operator==(EndDevice & endDevice) {
    return address==endDevice.getAddress() || name==endDevice.getName();
}

bool EndDevice::operator!=(EndDevice & endDevice) {
    return !this->operator==(endDevice);
}

std::ostream & operator << (std::ostream & os, EndDevice & endDevice){
    os << "Device's name: " << endDevice.getName() << std::endl;
    os << "Device's address: " << endDevice.getAddress() << std::endl;
    return os;
}