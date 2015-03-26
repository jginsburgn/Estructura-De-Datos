//
//  main.cpp
//  Tarea4.Listas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/24/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "TextEditor.h"

int main(int argc, const char * argv[]) {
    TextEditor * te = new TextEditor();
    te->initialize();
    delete te;
    return 0;
}
