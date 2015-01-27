//
//  main.cpp
//  Tarea1.Recursividad.Ejercicio3
//
//  Created by Jonathan Ginsburg on 1/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"

const int jumpRight = 3;
const int jumpDown = 2;

int possiblePaths(int rows, int columns, int currentRow, int currentColumn);

int main(int argc, const char * argv[]) {
    
    Helper::print("Welcome to the path counter. The counter can only follow paths that jump " + Helper::intToString(jumpRight) + " columns to the right and " + Helper::intToString(jumpDown) + " rows down. We start at the 0, 0 position and end at the rows-1, columns-1 position.");
    
    Helper::print("The total number of possible paths is: " + Helper::intToString(possiblePaths(Helper::read<int>("What is the number of rows in the board?"), Helper::read<int>("What is the number of columns in the board?"), 0, 0)));
    
    return 0;
}

int possiblePaths(int rows, int columns, int currentRow, int currentColumn){
    if (currentRow >= rows || currentColumn >= columns){
        return 0;
    }
    else if (currentRow == rows-1 && currentColumn == columns-1){
        return 1;
    }
    else{
        return possiblePaths(rows, columns, currentRow + jumpDown, currentColumn) + possiblePaths(rows, columns, currentRow, currentColumn + jumpRight);
    }
}