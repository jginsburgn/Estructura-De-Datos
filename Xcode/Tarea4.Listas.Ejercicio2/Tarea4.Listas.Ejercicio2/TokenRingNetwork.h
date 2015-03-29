//
//  TokenRingNetwork.h
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea4_Listas_Ejercicio2__TokenRingNetwork__
#define __Tarea4_Listas_Ejercicio2__TokenRingNetwork__


#include <stdio.h>
#include <iostream>
#include "CircularLinkedList.h"
#include "Helper.h"
#include <thread>
#include "EndDevice.h"
#include <unistd.h>

class TokenRingNetwork {
    
public:
    
    std::string name = "No name";
    CircularLinkedList<EndDevice *> * endDevices;
    
    int delay = 0;
    bool shouldRun = true;
    bool on = false;
    Token * token;
    
    bool addEndDevice();
    bool removeEndDevice();
    
    void initializeNetwork();
    void terminateNetwork();
    
    TokenRingNetwork() {
        delay = 0;
        endDevices = new CircularLinkedList<EndDevice *>();
        shouldRun = true;
        token = new Token(0);
        on = false;
    };
    TokenRingNetwork(std::string newName) : TokenRingNetwork() {name=newName; delay=0;};
    ~TokenRingNetwork() {
        delete endDevices;
    };
    
    CircularLinkedList<EndDevice *> * getEndDevices() {return endDevices;};
    
    Token * getToken() {return token;};
    
    int getDelay() {return delay;};
    
    bool isOn() {return on;};
    
    void openConsole();
    
    void printDevices();
    
    void accessConsoleOfDevice();
};

#endif /* defined(__Tarea4_Listas_Ejercicio2__TokenRingNetwork__) */
