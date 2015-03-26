//
//  main.cpp
//  EjerciciosEstructurasDeDatos.Ejercicio1
//
//  Created by Jonathan Ginsburg on 3/23/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include "Queue.h"


using namespace vcn;

int main(int argc, const char * argv[]) {
    Stack<int> * stack = new Stack<int>();
    for (int i = 0; i < 10; ++i) {
        stack->push(i);
    }
    
    std::cout << "La cola:" << std::endl;
    std::cout << *stack << std::endl;
    
    Queue<int> * aux = new Queue<int>();
    
    while (!stack->empty()) {
        aux->enqueue(stack->pop());
    }
    
    while (!aux->empty()) {
        stack->push(aux->dequeue());
    }
    
    delete aux;
    
    std::cout << "Inversa de la cola:" << std::endl;
    std::cout << *stack << std::endl;
    
    delete stack;
    
    return 0;
}
