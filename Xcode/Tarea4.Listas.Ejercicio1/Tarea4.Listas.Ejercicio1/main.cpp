//
//  main.cpp
//  Tarea4.Listas.Ejercicio1
//
//  Created by Jonathan Ginsburg on 3/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "Stack.h"

bool isMathInitialDelimiter(char c){
    switch (c) {
        case '(':
            return true;
            break;
        case '{':
            return true;
            break;
        case '[':
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool isMathFinalDelimiter(char c){
    switch (c) {
        case ')':
            return true;
            break;
        case '}':
            return true;
            break;
        case ']':
            return true;
            break;
        default:
            return false;
            break;
    }
}

char closerForOpener(char c){
    switch (c) {
        case '(':
            return ')';
            break;
        case '{':
            return '}';
            break;
        case '[':
            return ']';
            break;
        default:
            return ')';
            break;
    }
}

bool activateUserInteraction(){
    using namespace vcn;
    std::string mathEquation = Helper::readLine("Enter the math equation to parse:");
    Stack<char> * parenthesis = new Stack<char>();
    const char * charMathEquation = mathEquation.c_str();
    for (int i = 0; i < mathEquation.length(); ++i) {
        char currentChar = charMathEquation[i];
        if (isMathInitialDelimiter(currentChar)) {
            parenthesis->push(currentChar);
        }
        else if (isMathFinalDelimiter(currentChar)){
            if (parenthesis->empty()) {
                std::cout << "The equation is not balanced." << std::endl;
                return true;
            }
            else {
                Node<char> * currentNode = parenthesis->pop();
                if (closerForOpener(currentNode->getInfo())==currentChar) {
                    delete currentNode;
                }
                else {
                    std::cout << "The equation is not balanced." << std::endl;
                    return true;
                }
            }
        }
    }
    if (parenthesis->empty()) {
        std::cout << "The equation is balanced." << std::endl;
    }
    else std::cout << "The equation is not balanced." << std::endl;
    delete parenthesis;
    return true;
}

int main(int argc, const char * argv[]) {
    while (activateUserInteraction());
    return 0;
}
