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
#include <sstream>

class Helper {
public:
    
    static long double stringToLongDouble(std::string value){
        long double retVal =  0;
        try {
            retVal = std::stold(value);
        } catch (const std::out_of_range& invalido) {
            std::string description = "Number out of possible range...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        } catch (const std::invalid_argument& ia) {
            std::string description = "Argument is not a number...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        }
        return retVal;
    }
    
    static float stringToFloat(std::string value){
        float retVal =  0;
        try {
            retVal = std::stof(value);
        } catch (const std::out_of_range& invalido) {
            std::string description = "Number out of possible range...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        } catch (const std::invalid_argument& ia) {
            std::string description = "Argument is not a number...(";
            description.append(value);
            description.append(")");
            throw description.c_str();
        }
        return retVal;
    }
    
    static bool stringIsNumber(const std::string& s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it)) ++it;
        return !s.empty() && it == s.end();
    }
    
    static std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
        std::stringstream ss(s);
        std::string item;
        while (std::getline(ss, item, delim)) {
            elems.push_back(item);
        }
        return elems;
    }
    
    static std::vector<std::string> split(const std::string &s, char delim) {
        std::vector<std::string> elems;
        split(s, delim, elems);
        return elems;
    }
    
    static std::string readLine(std::string prompt){
        std::cout << prompt;
        std::cout.flush();
        std::string input = "";
        char character = std::cin.get();
        while (!(character <= 126 && character >= 32)) {
            character = std::cin.get();
        }
        while (character != '\n') {
            input += character;
            character = std::cin.get();
        }
        return input;
    }
    
    static void printSpace(){
        Helper::print("");
    }
    
    static int menu(std::string name, std::string options[], int availableOptions){
        Helper::print("");
        Helper::print("-----> Welcome to the " + name + " menu:");
        for (int i = 0; i < availableOptions; ++i) {
            Helper::print(options[i]);
        }
        int readValue = Helper::read<int>("Enter your choice:");
        Helper::print("");
        return readValue;
    }
    
    static std::string intToString(int integer){
        return std::to_string(integer);
    } //Converts from int to string.
    
    static std::string charToString(char character){
        std::stringstream ss;
        std::string s;
        ss << character;
        ss >> s;
        return s;
    } //Converts from a charatcter to a string.
    
    static void print(std::string message){
        std::cout << message << std::endl;
    } //Prints a message of type string.
    
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
