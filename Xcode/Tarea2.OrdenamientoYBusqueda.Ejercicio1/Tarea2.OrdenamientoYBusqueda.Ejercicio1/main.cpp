//
//  main.cpp
//  Tarea2.OrdenamientoYBusqueda.Ejercicio1
//
//  Created by Jonathan Ginsburg on 2/8/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Helper.h"
#include "GenericSearch.h"
#include "GenericSort.h"
#include "Book.h"

int lastBookIndex = 0;

bool isLibraryFull(int size){
    return lastBookIndex >= size;
}

bool isLibraryEmpty(){
    return lastBookIndex == 0;
}

void printLibrary(Book library[], int size){
    if (isLibraryEmpty()) {
        Helper::print("No books to show. Library is empty.");
        return;
    }
    Helper::print("Showing library now:");
    for (int i = 0; i < lastBookIndex; ++i) {
        std::cout << "Book number " << i + 1 << ":\n" << library[i] << std::endl;;
    }
    Helper::print("End of library.");
}

void printLibraryBooksOfDates(Book library[], int lowerYear, int higherYear){
    if (isLibraryEmpty()) {
        Helper::print("No books to show. Library is empty.");
        return;
    }
    
    Helper::print("Showing books between years " + Helper::intToString(lowerYear) + " and " + Helper::intToString(higherYear) + ": (extreme years are included)");
    
    for (int i = 0; i < lastBookIndex; ++i) {
        if (lowerYear <= library[i].year && higherYear >= library[i].year) {
            Helper::print("Book in position " + Helper::intToString(i+1) + ":");
            std::cout << library[i] << std::endl;
        }
    }
}

void printLibraryBooksOfAuthor(Book library[], std::string author){
    if (isLibraryEmpty()) {
        Helper::print("No books to show. Library is empty.");
        return;
    }
    
    Helper::print("Showing books published by author " + author);
    
    for (int i = 0; i < lastBookIndex; ++i) {
        if (author == library[i].author) {
            Helper::print("Book in position " + Helper::intToString(i+1) + ":");
            std::cout << library[i] << std::endl;
        }
    }
}

void printLibraryBooksOfPublishingHouse(Book library[], std::string publishingHouse){
    if (isLibraryEmpty()) {
        Helper::print("No books to show. Library is empty.");
        return;
    }
    
    Helper::print("Showing books published by publishing house " + publishingHouse);
    
    for (int i = 0; i < lastBookIndex; ++i) {
        if (publishingHouse == library[i].author) {
            Helper::print("Book in position " + Helper::intToString(i+1) + ":");
            std::cout << library[i] << std::endl;
        }
    }
}

Book createBookFromUserInput(){
    std::string title = Helper::read<std::string>("What is the title of your book?");
    std::string author = Helper::read<std::string>("What is the author?");
    int numberOfPages = Helper::read<int>("What is the number of pages?");
    int edition = Helper::read<int>("What is the edition?");
    int year = Helper::read<int>("What is the year of publication?");
    std::string publishingHouse = Helper::read<std::string>("What is the name of the Publishing House?");
    return Book(title, author, numberOfPages, edition, year, publishingHouse);
}

bool deleteBook(Book* library, int size){
    Helper::print("Let's now find a book to delete:");
    Helper::print("1 for choosing book's index.");
    Helper::print("2 for choosing book's characteristics.");
    Helper::print("3 for cancelling operation.");
    int bookIndex = -1;
    switch (Helper::read<int>("Enter your preference")) {
        case 1:
            printLibrary(library, size);
            bookIndex = Helper::read<int>("What is the index of the book to delete?") - 1;
            break;
        case 2:
            printLibrary(library, size);
            bookIndex = GenericSearch<Book>::sequentialSearch(library, size, createBookFromUserInput());
            break;
        default:
            Helper::print("Operation cancelled. Book not deleted.");
            return false;
            break;
    }
    if (bookIndex > lastBookIndex || bookIndex < 0) {
        Helper::print("No book at that position. Nothing was deleted.");
        return false;
    }
    else {
        library[bookIndex].resetBook();
        for (int i = bookIndex; i < lastBookIndex - 1; ++i) {
            library[i] = library[i+1];
        }
        library[--lastBookIndex].resetBook();
        Helper::print("Book successfully deleted.");
        return true;
    }
}

bool addBook(Book* library, int size, Book book, int position){
    Book emptyBook = Book();
    if (position >= size) {
        Helper::print("The book cannot be added because the library is full.");
        return false;
    }
    if(GenericSearch<Book>::sequentialSearch(library, size, book)!=-1) {
        Helper::print("The book cannot be added because it already exists in the library.");
        return false;
    }
    if (!(library[position] == emptyBook)) {
        Helper::print("That book cannot be added because position " + Helper::intToString(position + 1) + " is not empty. Try deleting that book first.");
        return false;
    }
    library[position] = book;
    ++lastBookIndex;
    Helper::print("Book Added.");
    return true;
}

bool userInteraction(Book* library, int size){
    Helper::print("");
    Helper::print("Main menu:");
    Helper::print("1 for adding a book.");
    Helper::print("2 for deleting a book.");
    Helper::print("3 for showing all books.");
    Helper::print("4 for showing all books published after a year.");
    Helper::print("5 for showing all books published before a year.");
    Helper::print("6 for showing all books published between two years");
    Helper::print("7 for showing all books published by an author.");
    Helper::print("8 for showing all books published by a publishing house.");
    switch (Helper::read<int>("Enter your choice:")) {
        case 1:
            Helper::print("\nChoice Number 1");
            if (isLibraryFull(size)) {
                Helper::print("Sorry, your library is full.");
                break;
            }
            addBook(library, size, createBookFromUserInput(), lastBookIndex);
            break;
        case 2:
            Helper::print("\nChoice Number 2");
            if (isLibraryEmpty()) {
                Helper::print("No books to delete, library is empty.");
            }
            deleteBook(library, size);
            break;
        case 3:
            Helper::print("\nChoice Number 3");
            printLibrary(library, size);
            break;
        case 4:
            Helper::print("\nChoice Number 4");
            printLibraryBooksOfDates(library, Helper::read<int>("What year?"), 2015);
            break;
        case 5:
            Helper::print("\nChoice Number 5");
            printLibraryBooksOfDates(library, -3000, Helper::read<int>("What year?"));
            break;
        case 6:
            Helper::print("\nChoice Number 6");
            printLibraryBooksOfDates(library, Helper::read<int>("Oldest year?"), Helper::read<int>("Newest year?"));
            break;
        case 7:
            Helper::print("\nChoice Number 7");
            printLibraryBooksOfAuthor(library, Helper::read<std::string>("Name of author to search for:"));
            break;
        case 8:
            Helper::print("\nChoice Number 8");
            printLibraryBooksOfPublishingHouse(library, Helper::read<std::string>("Name of publishing house to search for: "));
            break;
        default:
            Helper::print("Choice does not exist, try again.");
            break;
    }
    return true;
}

void fillLibrary(Book* library, int size){
    for (int i = 0; i < size; ++i) {
        Helper::print("Let's add book number " + Helper::intToString(i + 1) + ":");
        if (!addBook(library, size, createBookFromUserInput(), i)){
            --i;
        }
    }
}

int main(int argc, const char * argv[]) {
    int size = Helper::read<int>("What is the size of your library?");
    Book* library = new Book[size];
    if (Helper::read<int>("1 for filling your library right now or 2 for proceeding to the main menu.")==1) {
        fillLibrary(library, size);
    }
    while (userInteraction(library, size)) {}
    delete [] library;
    return 0;
}


