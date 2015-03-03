//
//  main.cpp
//  Tarea3.ListasEnlazadas.Ejercicio1
//
//  Created by Jonathan Ginsburg on 3/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//
#include "LinkedList.h"
#include "Helper.h"
#include <iostream>

using namespace vcn;

bool isPrime(int integer){
    if (integer < 2) return false;
    for (int i = 2; i < integer; ++i) {
        if (integer%i == 0) {
            return false;
        }
    }
    return true;
}
int nextPrime(int integer){
    int nextPrime = integer + 1;
    while (!isPrime(nextPrime)) {
        ++nextPrime;
    }
    return nextPrime;
}

LinkedList<int> * primes(int n, int p, int q){
    LinkedList<int> * list = new LinkedList<int>();
    int prime = p - 1;
    for (int i = 0; i < n; ++i) {
        if (nextPrime(prime) > q) {
            list->insertBack(prime);
        }
        else{
            prime = nextPrime(prime);
            list->insertBack(prime);
        }
    }
    return list;
}

void printListBackwards(Node<int> * node){
    if (node->getNext() == nullptr) {
        std::cout << *node << std::endl;
    }
    else {
        printListBackwards(node->getNext());
        std::cout << *node << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    int n = Helper::read<int>("What is the number of primes (n)?");
    int p = Helper::read<int>("What is the lower border of the closed interval (p)?");
    int q = Helper::read<int>("What is the upper border of the closed interval (q)?");
    if (p>q) {
        Helper::print("The closed interval is empty");
        return 0;
    }
    Helper::printSpace();
    Helper::print("Printing the first " + Helper::intToString(n) + " primes in the closed interval [" + Helper::intToString(p) + ", " + Helper::intToString(q) + "]. This is done in backward order.");
    LinkedList<int> * primesList = primes(n, p, q);
    printListBackwards(primesList->first());
    return 0;
}
