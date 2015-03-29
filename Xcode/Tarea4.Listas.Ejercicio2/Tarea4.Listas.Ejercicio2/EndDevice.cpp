//
//  EndDevice.cpp
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "EndDevice.h"

void EndDevice::deliverToken(Token * token){
    if (token->isAvailable()) {
        if (!outgoingCommunications->empty()) {
            Message m = outgoingCommunications->dequeue()->getInfo();
            token->setTransmitter(address);
            token->setReceiver(m.receiver);
            token->setMessage(m.message);
            lastSentMessage = m;
        }
    }
    else{
        if (address == token->getReceiver()) {
            Message m;
            m.message = token->fetchMessage();
            m.receiver = token->getReceiver();
            m.transmitter = token->getTransmitter();
            incomingCommunications->enqueue(m);
            if (address == token->getTransmitter()) {
                token->makeAvailable();
            }
        }
        else if (address == token->getTransmitter()) {
            if (token->getMessage() == Token::emptyMessage()) {
                token->makeAvailable();
            }
            else{
                std::string notification = "";
                notification.append(token->getReceiver());
                notification.append(" is not responding. Deleting message: ");
                notification.append(token->getMessage());
                std::ios_base::sync_with_stdio(false);
                std::cin.tie(nullptr);
                std::cerr.tie(nullptr);
                Helper::print(notification);
                token->makeAvailable();
            }
        }
    }
}

void EndDevice::printOutgoingCommunication(){
    int i = 0;
    while (i < outgoingCommunications->size()) {
        Message ed = outgoingCommunications->at(i)->getInfo();
        std::cout << "  **Outgoing message " << i+1 << ":" << std::endl;
        std::cout << "    ----Transmitter address: " << ed.transmitter << std::endl;
        std::cout << "    ----Receiver address: " << ed.receiver << std::endl;
        std::cout << "    ----Message: " << ed.message << std::endl;
        i = i + 1;
    }
}

void EndDevice::printIncomingCommunication(){
    int i = 0;
    while (i < incomingCommunications->size()) {
        Message ed = incomingCommunications->at(i)->getInfo();
        std::cout << "  **Outgoing message " << i+1 << ":" << std::endl;
        std::cout << "    ----Transmitter address: " << ed.transmitter << std::endl;
        std::cout << "    ----Receiver address: " << ed.receiver << std::endl;
        std::cout << "    ----Message: " << ed.message << std::endl;
        i = i + 1;
    }
}

void EndDevice::enqueueNewOutgoingMessage(){
    Message * m = new Message();
    m->transmitter = address;
    m->receiver = Helper::readLine("Enter the destination address:");
    m->message = Helper::readLine("Enter the message:");
    this->outgoingCommunications->enqueue(*m);
}

void EndDevice::openConsole(){
    const int availableOptions = 5;
    std::string menu[availableOptions];
    menu[0] = "1 for displaying device's status.";
    menu[1] = "2 for printing device's incomming communication.";
    menu[2] = "3 for printing device's outgoing communication.";
    menu[3] = "4 for enqueueing a new outgoing message";
    menu[4] = "5 for quitting the console of the device.";
    std::string menuName = "device ";
    menuName.append(name);
    menuName.append("'s console");
    while (true) {
        switch (Helper::menu(menuName, menu, availableOptions)) {
            case 1:
                Helper::print("Displaying device's status:");
                std::cout << "Device's name: " << name << std::endl;
                std::cout << "Device's address: " << address << std::endl;
                std::cout << "Device's last sent message: \n" << lastSentMessage << std::endl;
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
            case 5:
                Helper::print("Quitting console of device");
                Helper::print("Operation finished.");
                return;
                break;
            default:
                Helper::print("Choice not recognized");
                break;
        }
    }
}

bool EndDevice::operator==(const EndDevice & endDevice) {
    return address==endDevice.getAddress() || name==endDevice.getName();
}

bool EndDevice::operator!=(const EndDevice & endDevice) {
    return !this->operator==(endDevice);
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