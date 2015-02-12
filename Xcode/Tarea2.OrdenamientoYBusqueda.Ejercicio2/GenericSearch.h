//
//  GenericSearch.h
//  Tarea2.OrdenamientoYBusqueda.Ejercicio1
//
//  Created by Jonathan Ginsburg on 2/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//


#ifndef Generic_Search
#define Generic_Search

template <typename GenericType>
class GenericSearch {
    
public:
    
    static int binarySearch(GenericType vector[], int lowerBoundary, int upperBoundary, GenericType object){
        if (lowerBoundary >= upperBoundary) return -1; //Object not found.
        int middleIndex = (lowerBoundary + upperBoundary) / 2;
        if (vector[middleIndex]==object) {
            return middleIndex;
        }
        else if (vector[middleIndex] < object) {
            return binarySearch(vector, middleIndex + 1, upperBoundary, object);
        }
        else if (vector[middleIndex] > object) {
            return binarySearch(vector, lowerBoundary, middleIndex, object);
        }
        return -1;
    }
    
    static int sequentialSearch(GenericType vector[], int size, GenericType object){
        for (int i = 0; i < size; ++i){
            if (vector[i]==object) return i;
        }
        return -1;
    }
    
};

#endif
