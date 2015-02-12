//
//  GenericSort.h
//  Tarea2.OrdenamientoYBusqueda.Ejercicio1
//
//  Created by Jonathan Ginsburg on 2/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Generic_Sort
#define Generic_Sort

template <typename GenericType>
class GenericSort {
    
public:
    static void insertionSort(GenericType vector[], int size, bool compareFunc(GenericType, GenericType))
    {
        int i, j;
        GenericType tmp;
        for (i = 1; i < size; i++) {
            j = i;
            while (j > 0 && compareFunc(vector[j - 1], vector[j])) {
                tmp = vector[j];
                vector[j] = vector[j - 1];
                vector[j - 1] = tmp;
                j--;
            }
        }
    }
    
    static void bubbleSort(GenericType vector[], int size, bool compareFunc(GenericType, GenericType)){
        for(int x = 0; x < size; x++){
            for(int y = 0; y < size - 1; y++){
                if(compareFunc(vector[y], vector[y+1])){
                    GenericType temp = vector[y+1];
                    vector[y+1] = vector[y];
                    vector[y] = temp;
                }
            }
        }
    }
    
    static void selectionSort(GenericType vector[], int size, bool compareFunc(GenericType, GenericType)){
        for(int x = 0; x < size; x++){
            int index_of_min = x;
            for(int y = x; y < size; y++){
                if(compareFunc(vector[index_of_min], vector[y])){
                    index_of_min = y;
                }
            }
            GenericType temp = vector[x];
            vector[x] = vector[index_of_min];
            vector[index_of_min] = temp;
        }
    }
    
    static bool ascending(GenericType a, GenericType b){
        return a > b;
    }
    
    static bool descending(GenericType a, GenericType b){
        return a < b;
    }
};


#endif
