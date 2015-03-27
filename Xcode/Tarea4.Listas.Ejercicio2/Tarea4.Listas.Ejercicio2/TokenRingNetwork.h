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

class TokenRingNetwork {
    
private:
    
    std::string name = "No name";
    CircularLinkedList<EndDevice> * endDevices = new CircularLinkedList<EndDevice>();
    bool shouldRun = true;
    bool on = false;
    std::thread processingThread;
    
    bool addEndDevice();
    bool removeEndDevice();
    
    void initializeNetwork();
    void terminateNetwork();
    
public:
    int delay = 0;
    
    TokenRingNetwork() : delay(0) {} ;
    TokenRingNetwork(std::string newName) {name=newName; delay=0;};
    ~TokenRingNetwork() {
        delete endDevices;
    };
    
    CircularLinkedList<EndDevice> * getEndDevices() {return endDevices;};
    
    int getDelay() {return delay;};
    
    bool isOn() {return on;};
    
    void openConsole();
};

#endif /* defined(__Tarea4_Listas_Ejercicio2__TokenRingNetwork__) */
