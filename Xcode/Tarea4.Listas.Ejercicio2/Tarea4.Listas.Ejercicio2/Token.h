//
//  Token.h
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea4_Listas_Ejercicio2__Token__
#define __Tarea4_Listas_Ejercicio2__Token__

#include <stdio.h>
#include <iostream>
#include "Token.h"

using namespace vcn;

class Token {
    
private:
    
    std::string * transmitter;
    std::string * receiver;
    std::string * message;
    
public:
    
    static std::string emptyAddress() {return "0.0.0.0";};
    static std::string emptyMessage() {return "";};
    
    Token(int i) {
        transmitter = new std::string();
        receiver = new std::string();
        
        message =  new std::string();
        
        *transmitter = "0.0.0.0";
        *receiver = "0.0.0.0";
        *message = "";
    };
    ~Token(){};
    
    void setTransmitter(std::string newTransmitter) {*transmitter = newTransmitter;};
    void setReceiver(std::string newReceiver) {*receiver = newReceiver;};
    void setMessage(std::string newMessage) {*message = newMessage;};
    
    std::string getTransmitter() {return *transmitter;};
    std::string getReceiver() {return *receiver;};
    std::string getMessage() {return *message;};
    
    bool isAvailable() {return *message==Token::emptyMessage() && *transmitter==Token::emptyAddress() && *receiver == Token::emptyAddress();};
    
    void makeAvailable() {*message = Token::emptyMessage(); *transmitter = Token::emptyAddress(); *receiver = Token::emptyAddress();};
    
    std::string fetchMessage() { std::string oldMessage = *message; *message = Token::emptyMessage(); return oldMessage;};
    
};

#endif /* defined(__Tarea4_Listas_Ejercicio2__Token__) */
