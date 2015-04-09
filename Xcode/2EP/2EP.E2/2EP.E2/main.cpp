//
//  main.cpp
//  2EP.E2
//
//  Created by Jonathan Ginsburg on 4/9/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "LinkedList.h"

using namespace vcn;

LinkedList<int> * repeatedElements(LinkedList<int> * original){
    LinkedList<int> * repeated = new LinkedList<int>();
    for (int i = 0; i < original->size(); ++i) {
        for (int j = i + 1; j < original->size(); ++j) {
            if (original->at(i)->getInfo()==original->at(j)->getInfo()) {
                int r = original->at(i)->getInfo();
                bool shouldAdd = true;
                for (int k = 0; k < repeated->size(); ++k) {
                    if (r==repeated->at(k)->getInfo()) {
                        shouldAdd=false;
                    }
                }
                if (shouldAdd) {
                    repeated->insertFront(r);
                }
            }
        }
    }
    return repeated;
}

int main(int argc, const char * argv[]) {
    LinkedList<int> * original = new LinkedList<int>();
    int input = Helper::read<int>("Enter a number: 0 to terminate.");
    while (input!=0) {
        original->insertFront(input);
        input = Helper::read<int>("Enter a number: 0 to terminate.");
    }
    std::cout << *original << std::endl;
    LinkedList<int> *asdf = repeatedElements(original);
    std::cout << *asdf << std::endl;
    delete asdf;
    delete original;
    return 0;
}
