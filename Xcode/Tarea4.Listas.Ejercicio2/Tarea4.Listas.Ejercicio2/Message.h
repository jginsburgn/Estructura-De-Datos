//
//  Message.h
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Tarea4_Listas_Ejercicio2_Message_h
#define Tarea4_Listas_Ejercicio2_Message_h

#include <stdio.h>
#include <iostream>
#include "Token.h"

class Message{
public:
    
    std::string transmitter;
    std::string receiver;
    std::string message;
    
    Message() {
        transmitter = "0.0.0.0";
        receiver = "0.0.0.0";
        message = "";
    }
    

    
    bool operator == (Message & comparingMessage){
        return message==comparingMessage.message && transmitter==comparingMessage.transmitter && receiver==comparingMessage.receiver;
    }
    
    bool operator != (Message & comparingMessage) {
        return !this->operator==(comparingMessage);
    }
    
    friend std::ostream & operator << (std::ostream & os, Message & message){
        std::cout << "---  Transmitter: " << message.transmitter << std::endl;
        std::cout << "---  Receiver: " << message.receiver << std::endl;
        std::cout << "---  Message: " << message.message << std::endl;
        return os;
    }
};

#endif
