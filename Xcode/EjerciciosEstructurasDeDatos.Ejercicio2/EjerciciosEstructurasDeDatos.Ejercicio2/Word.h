//
//  Word.h
//  EjerciciosEstructurasDeDatos.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/23/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __EjerciciosEstructurasDeDatos_Ejercicio2__Word__
#define __EjerciciosEstructurasDeDatos_Ejercicio2__Word__

#include <stdio.h>
#include <iostream>

class Word {
private:
    std::string string = "";
public:
    Word() {};
    Word(std::string newString) { this->setString(newString); };
    
    std::string getString();
    void setString(std::string);
    
    friend std::ostream & operator << (std::ostream & os, Word & word);
    bool operator != (Word & word);
    bool operator == (Word & word);
};

#endif /* defined(__EjerciciosEstructurasDeDatos_Ejercicio2__Word__) */
