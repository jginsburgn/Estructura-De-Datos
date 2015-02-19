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

int main(int argc, const char * argv[]) {
    std::string options[3];
    options[0] = "1";
    options[1] = "2";
    options[2] = "3";
    std::cout << Helper::menu("main", options, 3) << std::endl;
    std::cout << *(options+1) << std::endl;
    return 0;
}
