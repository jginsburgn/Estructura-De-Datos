//
//  Word.cpp
//  EjerciciosEstructurasDeDatos.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/23/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Word.h"

std::string Word::getString(){
    return string;
}

void Word::setString(std::string newString){
    newString.erase(std::remove(newString.begin(), newString.end(), ' '), newString.end());
    string = newString;
}

std::ostream & operator << (std::ostream & os, Word & word){
    os << word.string;
    return os;
}

bool Word::operator != (Word & word){
    return this->string != word.getString();
}

bool Word::operator == (Word & word){
    return this->string == word.getString();
}