//
//  main.cpp
//  Tarea4.Listas.Ejercicio2
//
//  Created by Jonathan Ginsburg on 3/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Helper.h"
#include <stdio.h>
#include <iostream>
#include "TokenRingNetwork.h"

int main(int argc, const char * argv[]) {
    TokenRingNetwork * trn = new TokenRingNetwork("First Network");
    trn->delay = 0;
    trn->openConsole();
    return 0;
}
