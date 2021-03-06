//
//  Helper.h
//  Tarea1.Recursividad
//
//  Created by Jonathan Ginsburg on 1/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea1_Recursividad__Helper__
#define __Tarea1_Recursividad__Helper__

#include <stdio.h>
#include <iostream>
#include <string>

class Helper {
public:
    template <typename T>
    static T read(std::string prompt){
        T retVal;
        std::cout << prompt << std::endl;
        std::cin >> retVal;
        return retVal;
    } //Reads from console and returns value.
    
    template <typename T>
    static void printMatrix(T** matrix, int rows, int columns){
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } //Prints a matrix (assumes T has << operator overloaded).
    
    template <typename T>
    static T** buildMatrix(int rows, int columns){
        T** matrix = new T*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new T[columns];
        }
        return matrix;
    } //Builds a newly allocated bidimensional array (remember to destroy).
    
    template <typename T>
    static void destroyMatrix(T** matrix, int rows, int columns){
        for (int i = 0; i < rows; ++i) {
            delete [] matrix[i];
        }
        delete [] matrix;
    } //Destroys a bidimensional array.
};

#endif /* defined(__Tarea1_Recursividad__Helper__) */
