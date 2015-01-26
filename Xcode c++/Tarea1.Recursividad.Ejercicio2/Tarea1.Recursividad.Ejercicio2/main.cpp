//
//  main.cpp
//  Tarea1.Recursividad.Ejercicio2
//
//  Created by Jonathan Ginsburg on 1/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"

const char wall = '*';
const char noWall = ' ';
const char door = '>';
const char cursor = '?';

enum Direction{
    east, south, west, north
};

Direction rightOf(Direction last);
Direction leftOf(Direction last);
int movementInX(Direction dir);
int movementInY(Direction dir);
bool movementAvailable(char** laberynth, int rows, int columns, int row, int column);
void buildLaberynthWalls(char** laberynth, int rows, int columns);
void moveInLaberynth(char** laberynth, int rows, int columns, int currentRow, int currentColumn, Direction lastDirection);

int main(int argc, const char * argv[]) {
    
    Helper::print("Welcome to the laberynth solver. Some clarifications: '" + Helper::charToString(wall) + "' means a wall, '" + Helper::charToString(noWall) + " ' means no wall, '" + Helper::charToString(door) + "', means start or end,'" + Helper::charToString(cursor) + "' means cursor of builder. Please be sure to build a doable laberynth.");
    
    int rows = Helper::read<int>("Give me the number of rows in the laberynth:");
    int columns = Helper::read<int>("Give me the number of columns in the laberynth:");
    char **laberynth = Helper::buildMatrix<char>(rows, columns);
    buildLaberynthWalls(laberynth, rows, columns);
    
    Helper::print("This is your laberynth: ");
    Helper::printMatrix(laberynth, rows, columns);
    
    moveInLaberynth(laberynth, rows, columns, 0, 0, east);
    
    return 0;
}

Direction rightOf(Direction last){
    switch (last) {
        case east:
            return south;
            break;
        case south:
            return west;
            break;
        case west:
            return north;
            break;
        case north:
            return east;
            break;
        default:
            break;
    }
}

Direction leftOf(Direction last){
    switch (last) {
        case east:
            return north;
            break;
        case south:
            return east;
            break;
        case west:
            return south;
            break;
        case north:
            return west;
            break;
        default:
            break;
    }
}

int movementInX(Direction dir){
    switch (dir) {
        case north:
            return 0;
            break;
        case south:
            return 0;
            break;
        case east:
            return 1;
            break;
        case west:
            return -1;
            break;
        default:
            break;
    }
}

int movementInY(Direction dir){
    switch (dir) {
        case north:
            return -1;
            break;
        case south:
            return 1;
            break;
        case east:
            return 0;
            break;
        case west:
            return 0;
            break;
        default:
            break;
    }
}

bool movementAvailable(char** laberynth, int rows, int columns, int row, int column){
    if (row < 0 || column < 0 || row >= rows || column >= columns) {
        return false;
    }
    if (laberynth[column][row] == wall) return false;
    return true;
}

void buildLaberynthWalls(char** laberynth, int rows, int columns){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            laberynth[i][j] = cursor;
            Helper::printMatrix(laberynth, rows, columns);
            if ((i == 0 && j == 0) || (i == rows - 1 && j == columns - 1)) {
                laberynth[i][j] = door;
                continue;
            }
            if (Helper::read<char>("Do you want to add a wall in row: " + std::to_string(i + 1) + ", column: " + std::to_string(j + 1) + " of the laberynth: (y for yes, anything else for no): ") == 'y') {
                laberynth[i][j] = wall;
            }
            else laberynth[i][j] = noWall;
        }
    }
}

void moveInLaberynth(char** laberynth, int rows, int columns, int currentRow, int currentColumn, Direction lastDirection){
    if (currentRow == rows - 1 && currentColumn == columns - 1){
        Helper::print("We have arrived at our destination.");
    }
    else
    {
        Direction currentDirection = rightOf(lastDirection);
        if (movementAvailable(laberynth, rows, columns, currentRow + movementInX(currentDirection), currentColumn + movementInY(currentDirection))){
            Helper::print("Move from row:" + std::to_string(currentColumn + 1) + ", column:" + std::to_string(currentRow + 1) + " to row:" + std::to_string(currentColumn + movementInY(currentDirection) + 1) + ", column:" + std::to_string(currentRow + movementInX(currentDirection) + 1) + ".");
            moveInLaberynth(laberynth, rows, columns, currentRow + movementInX(currentDirection), currentColumn + movementInY(currentDirection), currentDirection);
        }
        else{
            while (!movementAvailable(laberynth, rows, columns, currentRow + movementInX(currentDirection), currentColumn + movementInY(currentDirection))) {
                currentDirection = leftOf(currentDirection);
            }
            Helper::print("Move from row:" + std::to_string(currentColumn + 1) + ", column:" + std::to_string(currentRow + 1) + " to row:" + std::to_string(currentColumn + movementInY(currentDirection) + 1) + ", column:" + std::to_string(currentRow + movementInX(currentDirection) + 1) + ".");
            moveInLaberynth(laberynth, rows, columns, currentRow + movementInX(currentDirection), currentColumn + movementInY(currentDirection), currentDirection);
        }
        
    }
}
