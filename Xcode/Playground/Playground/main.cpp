//
//  main.cpp
//  Playground
//
//  Created by Jonathan Ginsburg on 2/17/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"

class Libro {
    int isbn;
    
};

int fact(int a){
    if (a>0){
        if(a==1){
            return 1;
        }
        else{
            return a*fact(a-1);
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    Helper::print(Helper::intToString(fact(Helper::read<int>("Enter number:"))));
    return 0;
}
