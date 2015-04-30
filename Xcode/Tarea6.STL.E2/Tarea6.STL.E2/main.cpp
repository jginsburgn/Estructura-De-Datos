//
//  main.cpp
//  Tarea6.STL.E2
//
//  Created by Jonathan Ginsburg on 4/28/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Graph.h"
#include "Student.h"
#include "Helper.h"

std::ostream & operator << (std::ostream & os, const Edge<Student, int> & edge){
    os << "Relationship between students: " << *edge.getOrigin()->getInfo() << ", and " << *edge.getDestination()->getInfo() << "; of duration: " << *edge.getInfo();
    return os;
}

Graph<Student, int> students;

void listAllStudents(){
    Helper::print("Listing all students:");
    for (int i = 0; i < students.getVertices()->size(); ++i) {
        std::cout << i+1 << ") " << *students.getVertexAt(i) << "." << std::endl;
    }
}

void showMostStableStudent() {
    if (students.getVertices()->size() == 0) {
        return;
    }
    else if (students.getVertices()->size() == 1) {
        std::cout << (*students.getVertexAt(0)->getInfo()) << std::endl;
        return;
    }
    int pos = 0;
    double avg = 0;
    for (int i = 0 ; i < students.getVertices()->size(); ++i) {
        double add = 0;
        for (int j = 0; j < students.getVertexAt(i)->getEdges()->size(); ++j) {
            add += *((*students.getVertexAt(i)->getEdges())[j]->getInfo());
        }
        double navg = add/students.getVertexAt(i)->getEdges()->size();
        if (navg >= avg) {
            avg = navg;
        }
    }
    std::cout << (*students.getVertexAt(pos)->getInfo()) << std::endl;
}

void showStudentsWithNoRelationships() {
    for (int i = 0; i < students.getVertices()->size(); ++i) {
        if (students.getVertexAt(i)->getEdges()->size() == 0) {
            std::cout << *students.getVertexAt(i)->getInfo() << std::endl;
        }
    }
}

void showMostRelatedStudent(){
    if (students.getVertices()->size() == 0) {
        return;
    }
    else if (students.getVertices()->size() == 1) {
        std::cout << (*students.getVertexAt(0)->getInfo()) << std::endl;
        return;
    }
    int pos = 0;
    for (int i = 0 ; i < students.getVertices()->size(); ++i) {
        if (students.getVertexAt(i)->getEdges()->size() >= students.getVertexAt(pos)->getEdges()->size()) {
            pos = i;
        }
    }
    std::cout << (*students.getVertexAt(pos)->getInfo()) << std::endl;
}

void showPercentagesOfCompanyAndLoneliness(){
    listAllStudents();
    int s = Helper::read<int>("Choose the number of the student that you want to show the percentages of loneliness and companionship of.");
    Helper::print("Showing percentages");
    Vertex<Student, int> * student = students.getVertexAt(s-1);
    std::string info = "Percentage of companionship: ";
    double age = (double)student->getInfo()->getAge();
    double companionship = 0;
    for (int i = 0; i < student->getEdges()->size(); ++i) {
        companionship += (double)(*(*student->getEdges())[i]->getInfo());
    }
    std::string a = std::to_string(companionship/age * 100);
    std::string b = std::to_string(100 - companionship/age * 100);
    info.append(a);
    Helper::print(info);
    info = "Percentage of loneliness: ";
    info.append(b);
    Helper::print(info);
}

void showRelationshipOfStudent() {
    listAllStudents();
    int s = Helper::read<int>("Choose the number of the student that you want to show all the relationships of.");
    Helper::print("Listing all relationships of such student");
    for (int i = 0; i < students.getVertexAt(s-1)->getEdges()->size(); ++i) {
        std::cout << *(*students.getVertexAt(s-1)->getEdges())[i] << std::endl;
    }
}

void addRelationship(){
    listAllStudents();
    int a = Helper::read<int>("Choose the number of the student you want to relate.");
    int b = Helper::read<int>("Choose the number of the other student you want to relate.");
    try {
        students.addEdge(Helper::read<int>("Enter the duration of the relationship."), *students.getVertexAt(a-1)->getInfo(), *students.getVertexAt(b-1)->getInfo());
    } catch (const char * e) {
        Helper::print(e);
    }
}

void addStudent(){
    try {
        students.addVertex({Helper::readLine("Enter the name of the new student"), Helper::readLine("Enter the last name of the new student"), Helper::read<int>("Enter the age of the new student")});
    } catch (const char * e) {
        Helper::print(e);
    }
}

bool UI(){
    Helper::print("1 for creating a new student");
    Helper::print("2 for adding a relationship between students");
    Helper::print("3 for listing all students.");
    Helper::print("4 for listing all relationships of a specific student and their durations.");;
    Helper::print("5 for showing the percentages of the time that a student has been in a relationship and alone.");
    Helper::print("6 for showing the student with the most relationships.");
    Helper::print("7 for showing the students who have not been in a relationship.");
    Helper::print("8 for showing the most stable student.");
    Helper::print("9 for quitting.");
    int option = Helper::read<int>("Enter your option:");
    if (option == 1) {
        addStudent();
    }
    else if (option == 9){
        return false;
    }
    else if (option == 2){
        addRelationship();
    }
    else if (option == 3){
        listAllStudents();
    }
    else if (option == 4){
        showRelationshipOfStudent();
    }
    else if (option == 5){
        showPercentagesOfCompanyAndLoneliness();
    }
    else if (option == 6){
        showMostRelatedStudent();
    }
    else if (option == 7){
        showStudentsWithNoRelationships();
    }
    else if (option == 8){
        showMostStableStudent();
    }
    return true;
}

int main(int argc, const char * argv[]) {
    while (UI()) {}
    return 0;
}
