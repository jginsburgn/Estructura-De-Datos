//
//  Book.cpp
//  Tarea2.OrdenamientoYBusqueda.Ejercicio1
//
//  Created by Jonathan Ginsburg on 2/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Book.h"

Book::Book(std::string newTitle, std::string newAuthor, int newNumberOfPages, int newEdition, int newYear, std::string newPublishingHouse): title(newTitle), author(newAuthor), numberOfPages(newNumberOfPages), edition(newEdition), year(newYear), publishingHouse(newPublishingHouse){}

Book::Book():title("No Title"), author("No Author"), numberOfPages(0), edition(0), year(0), publishingHouse("No Publishing House"){}

std::ostream& operator<<(std::ostream& stream, Book book){
    stream << book.title << " by " << book.author << ". Number of pages: " << book.numberOfPages << ", Publishing House: " << book.publishingHouse << ", year: " << book.year << ", edition: " << book.edition << ".";
    return stream;
}

bool Book::operator==(Book book){
    if (this->title == book.title && this->author == book.author && this->numberOfPages == book.numberOfPages && this->edition == book.edition && this->year == book.year && this->publishingHouse == book.publishingHouse) {
        return true;
    }
    else return false;
}

void Book::resetBook(){
    this->title = "No Title";
    this->author = "No Author";
    this->numberOfPages = 0;
    this->edition = 0;
    this->year = 0;
    this->publishingHouse = "No Publishing House";
}