//
//  main.cpp
//  PrimerParcial.PrimerEjercicio
//
//  Created by Jonathan Ginsburg on 2/19/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <iostream>
#include "Helper.h"

std::string toHexDigit(int num){
    switch (num) {
        case 0:
            return "0";
            break;
        case 1:
            return "1";
            break;
        case 2:
            return "2";
            break;
        case 3:
            return "3";
            break;
        case 4:
            return "4";
            break;
        case 5:
            return "5";
            break;
        case 6:
            return "6";
            break;
        case 7:
            return "7";
            break;
        case 8:
            return "8";
            break;
        case 9:
            return "9";
            break;
        case 10:
            return "A";
            break;
        case 11:
            return "B";
            break;
        case 12:
            return "C";
            break;
        case 13:
            return "D";
            break;
        case 14:
            return "E";
            break;
        case 15:
            return "F";
            break;
        default:
            return "10";
            break;
    }
}

std::string toHex(int decimal){
    if (decimal/16 == 0){
        return toHexDigit(decimal%16);
    }
    else return toHex(decimal/16) + toHexDigit(decimal%16);
}

int main(int argc, const char * argv[]) {
    std::cout << toHex(Helper::read<int>("Give me decimal Number"));
    return 0;
}


