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
#include "Helper.h"

class EndDevice {
    
private:    
    
    std::string name;
    std::string address;
    Queue<Message> * outgoingCommunications;
    Queue<Message> * incomingCommunications;
    Message lastSentMessage;
    
public:
    
    EndDevice() {
        name = "No name";
        address = "0.0.0.0";
        outgoingCommunications = new Queue<Message>();
        incomingCommunications = new Queue<Message>();
    };
    ~EndDevice() {};
    
    EndDevice(const EndDevice & source){
        name = source.getName();
        address = source.getAddress();
        outgoingCommunications = new Queue<Message>();
        incomingCommunications = new Queue<Message>();
        
//        const Queue<Message> * ic = source.getIncomingCommunications();
//        const Queue<Message> * oc = source.getIncomingCommunications();
//        
//        for (int i = 0; i < ic->size(); ++i) {
//            Node<Message> * message = ic->at(i);
//            
//            incomingCommunications->enqueue();
//        }
        
    };// Deep copy
    
    std::string getName() const  {return name;};
    void setName(std::string newName) {name = newName;};
    
    std::string getAddress() const {return address;};
    void setAddress(std::string newAddress) {address = newAddress;};
    
    const Queue<Message> * getOutgoingCommunications() const { return outgoingCommunications; };
    const Queue<Message> * getIncomingCommunications() const { return incomingCommunications; };
    
    bool operator==(EndDevice & endDevice);
    bool operator!=(EndDevice & endDevice);
    
    bool operator==(const EndDevice & endDevice);
    bool operator!=(const EndDevice & endDevice);
    friend std::ostream & operator << (std::ostream & os, EndDevice & endDevice);
    
    void deliverToken(Token token);
    
    void openConsole();
    
    void printOutgoingCommunication();
    void printIncomingCommunication();
    void enqueueNewOutgoingMessage();
};

#endif /* defined(__Tarea4_Listas_Ejercicio2__EndDevice__) */
