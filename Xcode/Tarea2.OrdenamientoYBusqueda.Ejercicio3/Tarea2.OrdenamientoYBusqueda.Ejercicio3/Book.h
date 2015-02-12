//
//  Book.h
//  Tarea2.OrdenamientoYBusqueda.Ejercicio1
//
//  Created by Jonathan Ginsburg on 2/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef __Tarea2_OrdenamientoYBusqueda_Ejercicio1__Book__
#define __Tarea2_OrdenamientoYBusqueda_Ejercicio1__Book__

#include <iostream>

class Book{
public:
    std::string title;
    std::string author;
    int numberOfPages;
    int edition;
    int year;
    std::string publishingHouse;
    
    Book();
    Book(std::string newTitle, std::string newAuthor, int newNumberOfPages, int newEdition, int newYear, std::string newPublishingHouse);
    
    friend std::ostream& operator<<(std::ostream&, Book);
    bool operator==(Book book);
    void resetBook();
};

#endif /* defined(__Tarea2_OrdenamientoYBusqueda_Ejercicio1__Book__) */
