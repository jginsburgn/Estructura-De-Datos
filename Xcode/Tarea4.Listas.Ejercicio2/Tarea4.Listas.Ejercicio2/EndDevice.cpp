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

void EndDevice::printOutgoingCommunication(){
    
}

void EndDevice::printIncomingCommunication(){
    
}

void EndDevice::enqueueNewOutgoingMessage(){
    
}

void EndDevice::openConsole(){
    const int availableOptions = 4;
    std::string menu[availableOptions];
    menu[0] = "1 for displaying device's status.";
    menu[1] = "2 for printing device's incomming communication.";
    menu[2] = "3 for printing device's outgoing communication.";
    menu[3] = "4 for enqueueing a new outgoing message";
    std::string menuName = "device ";
    menuName.append(name);
    menuName.append("'s console");
    while (true) {
        switch (Helper::menu(menuName, menu, availableOptions)) {
            case 1:
                Helper::print("Displaying device's status:");
                std::cout << "Device's name: " << name << std::endl;
                std::cout << "Device's address: " << address << std::endl;
                std::cout << "Device's last sent message: " << lastSentMessage << std::endl;
                Helper::print("Operation finished.");
                break;
            case 2:
                Helper::print("Printing device's incomming communication");
                printIncomingCommunication();
                Helper::print("Operation finished.");
                break;
            case 3:
                Helper::print("Printing device's outgoing communication");
                printOutgoingCommunication();
                Helper::print("Operation finished.");
                break;
            case 4:
                Helper::print("Enqueueing a new outgoing message");
                enqueueNewOutgoingMessage();
                Helper::print("Operation finished.");
                break;
            default:
                Helper::print("Choice not recognized");
                break;
        }
    }
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