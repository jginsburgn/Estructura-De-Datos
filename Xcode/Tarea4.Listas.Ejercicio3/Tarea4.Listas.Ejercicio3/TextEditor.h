//
//  TextEditor.h
//  Tarea4.Listas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea4_Listas_Ejercicio3__TextEditor__
#define __Tarea4_Listas_Ejercicio3__TextEditor__

#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "DoubleCircularLinkedList.h"
#include "Helper.h"
#include <stdio.h>
#include <fstream>
#include <vector>

class TextEditor {
    
    std::fstream document;
    DoubleCircularLinkedList<std::vector<std::string>> * lines = new DoubleCircularLinkedList<std::vector<std::string>>();
    std::string currentDocumentName = "No document.";
    
    void loadLines();
    void printDocument();
    
    void openDocument();
    void saveDocument();
    void visualizeDocument();
    void freeTextEditing();
    void insertLine();
    void deleteLine();
    void insertWords();
    void deleteWords();
    
public:
    TextEditor() {};
    void initialize();
};

#endif /* defined(__Tarea4_Listas_Ejercicio3__TextEditor__) */
