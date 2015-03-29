//
//  TokenRingNetwork.cpp
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "TokenRingNetwork.h"

void TokenRingNetwork::accessConsoleOfDevice(){
    const int availableOptions = endDevices->size();
    std::string * menu = new std::string[availableOptions]();
    for (int i = 0; i < availableOptions; ++i) {
        EndDevice * ed = endDevices->at(i)->getInfo();
        std::string choice = "";
        choice.append(Helper::intToString(i+1));
        choice.append(" for accessing device ");
        choice.append(ed->getName());
        choice.append(" (");
        choice.append(ed->getAddress());
        choice.append(")");
        menu[i] = choice;
    }
    std::string menuName = "device console access ";
    int index = Helper::menu(menuName, menu, availableOptions) - 1;
    while (index < 0 || index >= availableOptions) {
        Helper::print("Option out of bounds.");
        index = Helper::menu(menuName, menu, availableOptions) - 1;
    }
    endDevices->at(index)->getInfo()->openConsole();
}

void TokenRingNetwork::printDevices() {
    int i = 0;
    while (i < endDevices->size()) {
        EndDevice * ed = endDevices->at(i)->getInfo();
        std::cout << "  **End device " << i+1 << ":" << std::endl;
        std::cout << "    ----Name: " << ed->getName() << std::endl;
        std::cout << "    ----Address: " << ed->getAddress() << std::endl;
        i = i + 1;
    }
}

bool TokenRingNetwork::addEndDevice(){
    
    EndDevice * newEndDevice = new EndDevice();
    newEndDevice->setName(Helper::readLine("Enter the name of the new device:"));
    std::string prompt = "Enter the address of ";
    prompt.append(newEndDevice->getName());
    prompt.append(":");
    newEndDevice->setAddress(Helper::readLine(prompt));
    
    bool deviceExists = false;
    for (int i = 0; i < endDevices->size(); ) {
        if (*(endDevices->at(i)->getInfo())==*newEndDevice) {
            deviceExists = true;
        }
        i = i +1;
    }
    
    if (deviceExists) {
        Helper::print("That device already exists in the network.");
        delete newEndDevice;
    }
    else{
        Helper::print("Connecting device");
        Node<EndDevice *> * node = new Node<EndDevice *>(newEndDevice);
        endDevices->insertBack(node);
    }
    
    return true;
}

bool TokenRingNetwork::removeEndDevice(){
    printDevices();
    delete endDevices->remove(Helper::read<int>("Enter the number of the device to disconnect.")-1);
    return true;
}

void f1(TokenRingNetwork * trn){
    Helper::print("Initializing parallel process");
    Node<EndDevice *> * tmp = trn->getEndDevices()->first();
    while (trn->shouldRun) {
        if (tmp != nullptr) {
            EndDevice * ed = tmp->getInfo();
            ed->deliverToken(trn->getToken());
            tmp = tmp->getNext();
            sleep(trn->delay);
        }
        else tmp = trn->getEndDevices()->first();
    }
    trn->on = false;
    Helper::print("Terminating parallel process");
    Helper::print("Operation finished.");
}

void f2(TokenRingNetwork * trn){
    const int availableOptions = 8;
    std::string menu[availableOptions];
    menu[0] = "1 for displaying network's status.";
    menu[1] = "2 for initializing network.";
    menu[2] = "3 for terminating network.";
    menu[3] = "4 for connecting a new device.";
    menu[4] = "5 for disconnecting a device.";
    menu[5] = "6 for adjusting network's delay.";
    menu[6] = "7 for quitting the network's console.";
    menu[7] = "8 for accessing the console of a connected device.";
    std::string menuName = "token ring network ";
    menuName.append(trn->name);
    menuName.append("'s console");
    while (trn->shouldRun) {
        std::string status = trn->isOn()?"running":"stopped";
        switch (Helper::menu(menuName, menu, availableOptions)) {
            case 1:
                Helper::print("Displaying network's status:");
                std::cout << "Network's name: " << trn->name << std::endl;
                std::cout << "Network's status: " << status << std::endl;
                std::cout << "Network's delay: " << Helper::intToString(trn->getDelay()) << std::endl;
                std::cout << "Network's devices: " << std::endl;
                trn->printDevices();
                Helper::print("Operation finished.");
                break;
            case 2:
                Helper::print("Initializing network");
                Helper::print("Operation finished.");
                break;
            case 3:
                Helper::print("Terminating network");
                trn->terminateNetwork();
                break;
            case 4:
                Helper::print("Connecting a new device to the network");
                trn->addEndDevice();
                Helper::print("Operation finished.");
                break;
            case 5:
                Helper::print("Disconnecting a device from the network");
                trn->removeEndDevice();
                Helper::print("Operation finished.");
                break;
            case 6:
                Helper::print("Setting network's delay");
                trn->delay = Helper::read<int>("Enther the new network's delay:");
                Helper::print("Operation finished.");
                break;
            case 7:
                Helper::print("Quitting network's console is not allowed when network is running.");
                Helper::print("Operation finished.");
                break;
            case 8:
                Helper::print("Accessing console of a connected device.");
                trn->accessConsoleOfDevice();
                Helper::print("Operation finished.");
                break;
            default:
                Helper::print("Choice not recognized");
                break;
        }
    }

}

void TokenRingNetwork::initializeNetwork(){
    shouldRun = true;
    on = true;
    std::thread first(f1, this);
    sleep(2);
    Helper::print("Operation finished.");
    std::thread second(f2, this);
    first.join();
    second.join();
}

void TokenRingNetwork::terminateNetwork(){
    shouldRun = false;
}

void TokenRingNetwork::openConsole(){
    const int availableOptions = 8;
    std::string menu[availableOptions];
    menu[0] = "1 for displaying network's status.";
    menu[1] = "2 for initializing network.";
    menu[2] = "3 for terminating network.";
    menu[3] = "4 for connecting a new device.";
    menu[4] = "5 for disconnecting a device.";
    menu[5] = "6 for adjusting network's delay.";
    menu[6] = "7 for quitting the network's console.";
    menu[7] = "8 for accessing the console of a connected device.";
    std::string menuName = "token ring network ";
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
                std::cout << "Network's devices: " << std::endl;
                printDevices();
                Helper::print("Operation finished.");
                break;
            case 2:
                Helper::print("Initializing network");
                initializeNetwork();
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
                terminateNetwork();
                sleep(1);
                Helper::print("Operation finished.");
                return;
                break;
            case 8:
                Helper::print("Accessing console of a connected device.");
                accessConsoleOfDevice();
                Helper::print("Operation finished.");
                break;
            default:
                Helper::print("Choice not recognized");
                break;
        }
    }
}