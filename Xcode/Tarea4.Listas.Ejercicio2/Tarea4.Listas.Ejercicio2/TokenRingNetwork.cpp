//
//  TokenRingNetwork.cpp
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "TokenRingNetwork.h"

bool TokenRingNetwork::addEndDevice(){
    
    EndDevice * newEndDevice = new EndDevice();
    newEndDevice->setName(Helper::readLine("Enter the name of the new device:"));
    std::string prompt = "Enter the address of ";
    prompt.append(newEndDevice->getName());
    prompt.append(":");
    newEndDevice->setAddress(Helper::readLine(prompt));
    
    bool deviceExists = false;
    for (int i = 0; i < endDevices->size(); ++i) {
        if (endDevices->at(i)->getInfo()==*newEndDevice) {
            deviceExists = true;
        }
    }
    if (deviceExists) {
        Helper::print("That device already exists in the network.");
        delete newEndDevice;
    }
    else{
        Helper::print("Connecting device");
        endDevices->insertFront(*newEndDevice);
    }
    
    return true;
}

bool TokenRingNetwork::removeEndDevice(){
    return true;
}

void TokenRingNetwork::initializeNetwork(){
    
}

void TokenRingNetwork::terminateNetwork(){
    
}

void TokenRingNetwork::openConsole(){
    const int availableOptions = 7;
    std::string menu[availableOptions];
    menu[0] = "1 for displaying network's status.";
    menu[1] = "2 for initializing network.";
    menu[2] = "3 for terminating network.";
    menu[3] = "4 for connecting a new device.";
    menu[4] = "5 for disconnecting a device.";
    menu[5] = "6 for adjusting network's delay.";
    menu[6] = "7 for quitting the network's console.";
    std::string menuName = "token ring network : ";
    menuName.append(name);
    menuName.append("'s console");
    while (true) {
        std::string status = isOn()?"running":"stopped";
        switch (Helper::menu(menuName, menu, availableOptions)) {
            case 1:
                Helper::print("Displaying network's status:");
                std::cout << "Network's name: " << name << std::endl;
                std::cout << "Network's status: " << status << std::endl;
                std::cout << "Network's delay: " << Helper::intToString(getDelay()) << std::endl;
                std::cout << "Network's devices: " << std::endl << *endDevices << std::endl;
                Helper::print("Operation finished.");
                break;
            case 2:
                Helper::print("Initializing network");
                initializeNetwork();
                Helper::print("Operation finished.");
                break;
            case 3:
                Helper::print("Terminating network");
                terminateNetwork();
                Helper::print("Operation finished.");
                break;
            case 4:
                Helper::print("Connecting a new device to the network");
                addEndDevice();
                Helper::print("Operation finished.");
                break;
            case 5:
                Helper::print("Disconnecting a device from the network");
                removeEndDevice();
                Helper::print("Operation finished.");
                break;
            case 6:
                Helper::print("Setting network's delay");
                delay = Helper::read<int>("Enther the new network's delay:");
                Helper::print("Operation finished.");
                break;
            case 7:
                Helper::print("Quitting network's console");
                Helper::print("Operation finished.");
                return;
                break;
            default:
                Helper::print("Choice not recognized");
                break;
        }
    }
}