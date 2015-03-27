//
//  EndDevice.h
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea4_Listas_Ejercicio2__EndDevice__
#define __Tarea4_Listas_Ejercicio2__EndDevice__


#include <stdio.h>
#include <iostream>
#include "Queue.h"
#include "Message.h"
#include "Token.h"

class EndDevice {
    
private:    
    
    std::string name;
    std::string address;
    Queue<Message> * outgoingCommunications;
    Queue<Message> * incomingCommunications;
    LinkedList<Message> * history;
    Message lastSentMessage;
    
public:
    
    EndDevice() : name("No name"), address("0.0.0.0"), outgoingCommunications(new Queue<Message>()), incomingCommunications(new Queue<Message>()), history(new LinkedList<Message>()) {};
    ~EndDevice() {};
    
    std::string getName() {return name;};
    void setName(std::string newName) {name = newName;};
    
    std::string getAddress() {return address;};
    void setAddress(std::string newAddress) {address = newAddress;};
    
    bool operator==(EndDevice & endDevice);
    bool operator!=(EndDevice & endDevice);
    friend std::ostream & operator << (std::ostream & os, EndDevice & endDevice);
    
    void deliverToken(Token token);
    
    void openConsole();
};

#endif /* defined(__Tarea4_Listas_Ejercicio2__EndDevice__) */
