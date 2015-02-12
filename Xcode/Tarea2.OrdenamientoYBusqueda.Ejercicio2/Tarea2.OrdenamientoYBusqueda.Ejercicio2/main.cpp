//
//  main.cpp
//  Tarea2.OrdenamientoYBusqueda.Ejercicio2
//
//  Created by Jonathan Ginsburg on 2/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <ctime>
#include "Helper.h"
#include "GenericSort.h"

#define numberOfStrings 1000

std::string randomString(const int len) {
    char s[len + 1];
    static const char alphanum[] =
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    s[len] = '\0';
    return std::string(s);
}

void fillStrings(std::string array[], int size){
    for (int i = 0; i < size; ++i) {
        array[i] = randomString(rand() % 50 +1);
    }
}

void printStrings(std::string array[], int size){
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << std::endl;
    }
}

void sortAscending(std::string strings[]){
    for (int i = 0; i < 3; ++i) {
        Helper::print("");
    }
    Helper::print("----> Sort in ascending order menu:");
    Helper::print("1 to use bubble sort.");
    Helper::print("2 to use insertion sort.");
    Helper::print("3 to use selection sort.");
    switch (Helper::read<int>("Enter your choice:")) {
        case 1:
            GenericSort<std::string>::bubbleSort(strings, numberOfStrings, GenericSort<std::string>::ascending);
            break;
        case 2:
            GenericSort<std::string>::insertionSort(strings, numberOfStrings, GenericSort<std::string>::ascending);
            break;
        case 3:
            GenericSort<std::string>::selectionSort(strings, numberOfStrings, GenericSort<std::string>::ascending);
            break;
        default:
            Helper::print("Option not recognized");
            break;
    }
}

void sortDescending(std::string strings[]){
    for (int i = 0; i < 3; ++i) {
        Helper::print("");
    }
    Helper::print("----> Sort in descending order menu:");
    Helper::print("1 to use bubble sort.");
    Helper::print("2 to use insertion sort.");
    Helper::print("3 to use selection sort.");
    switch (Helper::read<int>("Enter your choice:")) {
        case 1:
            GenericSort<std::string>::bubbleSort(strings, numberOfStrings, GenericSort<std::string>::descending);
            break;
        case 2:
            GenericSort<std::string>::insertionSort(strings, numberOfStrings, GenericSort<std::string>::descending);
            break;
        case 3:
            GenericSort<std::string>::selectionSort(strings, numberOfStrings, GenericSort<std::string>::descending);
            break;
        default:
            Helper::print("Option not recognized");
            break;
    }
}

bool userInteraction(std::string strings[]){
    for (int i = 0; i < 3; ++i) {
        Helper::print("");
    }
    Helper::print("----> Main menu:");
    Helper::print("1 to fill array randomly.");
    Helper::print("2 to print array.");
    Helper::print("3 to sort array in ascending order.");
    Helper::print("4 to sort array in descending order.");
    Helper::print("5 to end program.");
    switch (Helper::read<int>("Enter your choice:")) {
        case 1:
            fillStrings(strings, numberOfStrings);
            Helper::print("Done.");
            break;
        case 2:
            printStrings(strings, numberOfStrings);
            Helper::print("Done.");
            break;
        case 3:
            sortAscending(strings);
            Helper::print("Done.");
            break;
        case 4:
            sortDescending(strings);
            Helper::print("Done.");
            break;
        case 5:
            return false;
            break;
        default:
            Helper::print("Option not recognized.");
            break;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    std::string strings[numberOfStrings];
    while (userInteraction(strings)) {};
    return 0;
}
