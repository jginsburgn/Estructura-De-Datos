//
//  main.cpp
//  Tarea4.Listas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/24/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "DoubleCircularLinkedList.h"

int main(int argc, const char * argv[]) {
    using namespace vcn;
    DoubleCircularLinkedList<int> * dcll = new DoubleCircularLinkedList<int>();
    
    //se insertan elementos
    dcll->insert(5, 10);
    dcll->insert(7, 0);
    dcll->insertFront(4);
    dcll->insertBack(8);
    dcll->insert(1, 0);
    
    //se imprime la lista
    std::cout << "Lista se imprime:" << std::endl;
    std::cout << *dcll << std::endl;
    
    //se imprime la lista en reversa
    std::cout << "Lista se imprime en reversa:" << std::endl;
    Node<int> * temp = dcll->at(dcll->size()-1);
    for (int i = 0; i < dcll->size(); ++i) {
        std::cout << *temp << std::endl;
        temp = temp->getPrevious();
    }
    
    std::cout << '\n';
    
    //se imprime lista a partir del nodo en posicion 2 hacia adelante
    std::cout << "Se imprime lista a partir del nodo en posicion 2 hacia adelante:" << std::endl;
    temp = dcll->at(2);
    for (int i = 0; i < dcll->size(); ++i) {
        std::cout << *temp << std::endl;
        temp = temp->getNext();
    }
    
    std::cout << "Se remueve lo que hay en la posición 3" << std::endl;
    temp = dcll->remove(3);
    if (temp->getNext() != nullptr || temp->getPrevious() != nullptr) {
        std::cout << "Problem with the removal of nodes" << std::endl;
    }
    delete temp;
    
    std::cout << '\n';
    
    //se imprime la lista en reversa
    std::cout << "Lista se imprime en reversa:" << std::endl;
    temp = dcll->at(dcll->size()-1);
    for (int i = 0; i < dcll->size(); ++i) {
        std::cout << *temp << std::endl;
        temp = temp->getPrevious();
    }
    
    std::cout << "Se borra la lista" << std::endl;
    dcll->clear();
    
    std::cout << '\n';
    
    //se imprime la lista en reversa
    std::cout << "Lista se imprime en reversa:" << std::endl;
    temp = dcll->at(dcll->size()-1);
    for (int i = 0; i < dcll->size(); ++i) {
        std::cout << *temp << std::endl;
        temp = temp->getPrevious();
    }
    
    delete dcll;
    return 0;
}
