//
//  main.cpp
//  EjerciciosEstructurasDeDatos.Ejercicio1
//
//  Created by Jonathan Ginsburg on 3/23/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Stack.h"
#include "Queue.h"
#include "Helper.h"
#include "Word.h"


using namespace vcn;

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

int main(int argc, const char * argv[]) {
    
    std::string sentence = Helper::readLine("Enter a sentence:");
    std::vector<std::string> splittedSentence = split(sentence, ' ');
    
    Stack<Word> * stack = new Stack<Word>();
    for (int i = 0; i < splittedSentence.size(); i++) {
        stack->push(Word(splittedSentence[i]));
    }
    
    std::cout << "Inverse:" << std::endl;
    
    for (int i = 0; i < splittedSentence.size(); i++) {
        std::cout << stack->pop()->getInfo().getString() << " ";
    }
    
    std::cout << std::endl;
    
    delete stack;
    
    return 0;
}
