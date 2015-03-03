//
//  main.cpp
//  Tarea3.ListasEnlazadas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "LinkedList.h"

using namespace vcn;

void printLists(LinkedList<int> * m, LinkedList<int> * n, LinkedList<int> * p){
    Helper::print("M = {");
    std::cout << *m;
    Helper::print("}");
    Helper::printSpace();
    Helper::print("N = {");
    std::cout << *n;
    Helper::print("}");
    Helper::printSpace();
    Helper::print("P = {");
    std::cout << *p;
    Helper::print("}");
}

LinkedList<int> * productOf(LinkedList<int> * N, LinkedList<int> * M){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < M->size(); ++i) {
        for (int j = 0; j < N->size(); ++j) {
            p->insertBack(M->at(i)->getInfo()*N->at(j)->getInfo());
        }
    }
    return p;
}

LinkedList<int> * intersectionOf(LinkedList<int> * M, LinkedList<int> * N){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < M->size(); ++i) {
        for (int j = 0; j < N->size(); ++j) {
            if (M->at(i)->getInfo() == N->at(j)->getInfo()) {
                p->insertBack(M->at(i)->getInfo());
            }
        }
    }
    return p;
}

LinkedList<int> * subtractionOf(LinkedList<int> * M, LinkedList<int> * N){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < M->size(); ++i) {
        bool repeated = false;
        for (int j = 0; j < N->size(); ++j) {
            if (M->at(i)->getInfo() == N->at(j)->getInfo()) {
                repeated = true;
                break;
            }
        }
        if (!repeated) {
            p->insertBack(M->at(i)->getInfo());
        }
    }
    return p;
}

LinkedList<int> * unionOf(LinkedList<int> * N, LinkedList<int> * M){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < N->size(); ++i) {
        p->insertBack(N->at(i)->getInfo());
    }
    for (int i = 0; i < M->size(); ++i) {
        bool repeated = false;
        for (int j = 0; j < N->size(); ++j) {
            if (N->at(j)->getInfo() == M->at(i)->getInfo()) repeated = true;
        }
        if (!repeated) {
            p->insertBack(M->at(i)->getInfo());
        }
    }
    return p;
}

LinkedList<int> * buildList(int length){
    LinkedList<int> * newLinkedList = new LinkedList<int>();
    for (int i = 0; i < length; ++i) {
        newLinkedList->insertBack(Helper::read<int>("Enter number " +  Helper::intToString(i+1) + " to the list"));
    }
    return newLinkedList;
}

void mainMenu(LinkedList<int> * m, LinkedList<int> * n){
    std::string options[5];
    options[0] = "1 for P = N U M";
    options[1] = "2 for P = N - M";
    options[2] = "3 for P = M - N";
    options[3] = "4 for P = N * M";
    options[4] = "5 for P = N intersection M";
    LinkedList<int> * p = new LinkedList<int>();
    while (true) {
        switch (Helper::menu("main", options, 5)) {
            case 1:
                delete p;
                p = unionOf(m, n);
                printLists(m, n, p);
                break;
            case 2:
                delete p;
                p = subtractionOf(n, m);
                printLists(m, n, p);
                break;
            case 3:
                delete p;
                p = subtractionOf(m, n);
                printLists(m, n, p);
                break;
            case 4:
                delete p;
                p = productOf(m, n);
                printLists(m, n, p);
                break;
            case 5:
                delete p;
                p = intersectionOf(m, n);
                printLists(m, n, p);
                break;
            default:
                Helper::print("Invalid choice.");
                break;
        }
    }
}

int main(int argc, const char * argv[]) {
    LinkedList<int> * m = buildList(Helper::read<int>("What is the size of the list M?"));
    LinkedList<int> * n = buildList(Helper::read<int>("What is the size of the list N?"));
    mainMenu(m, n);
    return 0;
}
