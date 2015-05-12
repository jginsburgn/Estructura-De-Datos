//
//  main.cpp
//  EF.E2.Alfombra
//
//  Created by Jonathan Ginsburg on 5/12/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "BinaryTree.h"
#include <sstream>
#include <string>
#include <cmath>

//Código consultado en http://en.wikipedia.org/wiki/Sierpinski_carpet
bool shouldDraw(int x, int y)
{
    while(x>0 || y>0)
    {
        if(x%3==1 && y%3==1)
            return false;
        x /= 3;
        y /= 3;
    }
    return true;
}
//Aquí termina el código consultado

int main(int argc, const char * argv[]) {
    int dimension = Helper::read<int>("Enter the dimension for the carpet to draw.");
    for (int i = 0; i < pow(3, dimension); ++i) {
        for (int j = 0; j < pow(3, dimension); ++j) {
            if (shouldDraw(i, j)) {
                std::cout << " ";
            }
            else std::cout << "#";
        }
        std::cout << std::endl;
    }
    return 0;
}
