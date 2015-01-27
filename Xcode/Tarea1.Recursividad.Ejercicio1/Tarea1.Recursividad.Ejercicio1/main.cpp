//
//  main.cpp
//  Tarea1.Recursividad
//
//  Created by Jonathan Ginsburg on 1/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <string>
#include <math.h>

#include "Helper.h"

void firstExercise(int** matrix, int dimension, int row, int column);

int main(int argc, const char * argv[]) {
    
    int dimension = Helper::read<int>("Enter square array dimension");
    int** matrix = Helper::buildMatrix<int>(dimension, dimension);
    
    firstExercise(matrix, dimension, 0, 0);
    
    Helper::printMatrix<int>(matrix, dimension, dimension);
    Helper::destroyMatrix<int>(matrix, dimension, dimension);
    return 0;
}

void firstExercise(int** matrix, int dimension, int row, int column){
    if (row == dimension - 1 && column == dimension - 1){
        matrix[row][column] = pow(2, dimension - 1);
    }
    else{
        if (row == dimension - 1){
            matrix[row][column] = pow(2, column);
            firstExercise(matrix, dimension, 0, column + 1);
        }
        else{
            if(row < column) matrix[row][column] = pow(2, row);
            else matrix[row][column] = pow(2, column);
            firstExercise(matrix, dimension, row + 1, column);
        }
    }
}