//
//  main.cpp
//  Tarea3.ListasEnlazadas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "Helper.h"
#include "LinkedList.h"
#include "OrderedLinkedList.h"
#include "Person.h"
#define availableOptions 7


using namespace vcn;

Person * getPerson();
bool personExists(OrderedLinkedList<Person> * persons, Person * person);
void mainMenu();
void addPerson(OrderedLinkedList<Person> * persons);
void deletePerson(OrderedLinkedList<Person> * persons);
void lookForPerson(OrderedLinkedList<Person> * persons);
void listAllPersons(OrderedLinkedList<Person> * persons);
void deleteAllPersons(OrderedLinkedList<Person> * persons);
void countAllPersons(OrderedLinkedList<Person> * persons);

int main(int argc, const char * argv[]) {
    mainMenu();
    return 0;
}

void mainMenu(){
    OrderedLinkedList<Person> * persons = new OrderedLinkedList<Person>(OrderedLinkedList<Person>::ascending);
    std::string options[availableOptions];
    options[0] = "1 for adding a person.";
    options[1] = "2 for looking for a person.";
    options[2] = "3 for deleting for a person.";
    options[3] = "4 for listing all persons.";
    options[4] = "5 for deleting all persons.";
    options[5] = "6 for counting all persons.";
    options[6] = "7 for terminating.";
    bool run = true;
    while (run) {
        switch (Helper::menu("main", options, availableOptions)) {
            case 1:
                addPerson(persons);
                break;
            case 2:
                lookForPerson(persons);
                break;
            case 3:
                deletePerson(persons);
                break;
            case 4:
                listAllPersons(persons);
                break;
            case 5:
                deleteAllPersons(persons);
                break;
            case 6:
                countAllPersons(persons);
                break;
            case 7:
                run = false;
                break;
            default:
                Helper::print("Invalid Choice.");
                break;
        }
    }
}

Person * getPerson(){
    Person * newPerson = new Person();
    newPerson->setFirstName(Helper::readLine("What is the name of the person?"));
    newPerson->setLastName(Helper::readLine("What is the last name of " + newPerson->getFirstName() + "?"));
    newPerson->setLastLastName(Helper::readLine("What is the last last name of " + newPerson->getFirstName() + "?"));
    newPerson->setAge(Helper::read<int>("How old is " + newPerson->getFirstName() + "?"));
    Date newDateOfBirth;
    newDateOfBirth.year = Helper::read<int>("What is the year of his birth?");
    newDateOfBirth.month = Helper::read<int>("What is the month of his birth?");
    newDateOfBirth.day = Helper::read<int>("What is the day of his birth?");
    newPerson->setDateOfBirth(newDateOfBirth);
    return newPerson;
}

void addPerson(OrderedLinkedList<Person> * persons){
    Helper::print("Adding a new person:");
    Person * person = getPerson();
    if (personExists(persons, person)) Helper::print("That person is already in the list.");
    else persons->insert(*person);
    delete person;
    Helper::print("Done.");
}

void deletePerson(OrderedLinkedList<Person> * persons){
    Helper::print("Deleting a person:");
    listAllPersons(persons);
    persons->remove(Helper::read<int>("What is the index of the person to delete?")-1);
    Helper::print("Done.");
}

bool personExists(OrderedLinkedList<Person> * persons, Person * person){
    for (int i = 0; i < persons->size(); ++i) {
        if (persons->at(i)->getInfo() == *person) {
            return true;
        }
    }
    return false;
}

void lookForPerson(OrderedLinkedList<Person> * persons){
    Helper::print("Looking for a person:");
    Person * person = getPerson();
    bool found = false;
    for (int i = 0; i < persons->size(); ++i) {
        if (persons->at(i)->getInfo() == *person) {
            Helper::print("The person you are looking for is in index " + Helper::intToString(i+1) + " of the list.");
            found = true;
            break;
        }
    }
    if (!found) Helper::print("The person you are looking for is not in the list.");
    delete person;
    Helper::print("Done.");
}

void listAllPersons(OrderedLinkedList<Person> * persons){
    Helper::print("Listing all persons:");
    for (int i = 0; i < persons->size(); ++i) {
        std::cout << "Person " << i+1 << ") " << persons->at(i)->getInfo() << std::endl;
    }
    Helper::print("Done.");
}

void deleteAllPersons(OrderedLinkedList<Person> * persons){
    Helper::print("Deleting all persons:");
    persons->clear();
    Helper::print("Done.");
}

void countAllPersons(OrderedLinkedList<Person> * persons){
    Helper::print("Printing the number of persons:");
    Helper::print(Helper::intToString(persons->size()));
    Helper::print("Done");
}