//
//  main.cpp
//  2EP.E1
//
//  Created by Jonathan Ginsburg on 4/9/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Stack.h"
#include "Helper.h"

std::string toBinary(std::string decimal){
    using namespace vcn;
    std::string binary = "";
    int number = atoi(decimal.c_str());
    Stack<int> * stack = new Stack<int>();
    while (number != 0) {
        stack->push(number%2);
        number = number/2;
    }
    while (!stack->empty()) {
        binary.append(Helper::intToString(stack->pop()->getInfo()));
    }
    delete stack;
    return binary;
}

int main(int argc, const char * argv[]) {
    Helper::print(toBinary(Helper::readLine("Write a number:")));
    return 0;
}
