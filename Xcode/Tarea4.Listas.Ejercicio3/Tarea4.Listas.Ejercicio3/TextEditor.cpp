//
//  TextEditor.cpp
//  Tarea4.Listas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/25/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "TextEditor.h"
#define mainMenuOptions 9

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

std::vector<std::string> insertToVectorAtPosition(std::vector<std::string> vector, std::vector<std::string> newVector, int position){
    LinkedList<std::string> * temp = new LinkedList<std::string>();
    std::vector<std::string> returner;
    for (int i = 0; i < vector.size(); ++i) {
        temp->insertBack(vector[i]);
    }
    for (int i = 0; i < newVector.size(); ++i) {
        temp->insert(newVector[i], position + i);
    }
    for (int i = 0; i < temp->size(); ++i) {
        returner.push_back(temp->at(i)->getInfo());
    }
    delete temp;
    return returner;
}

void TextEditor::printDocument(){
    for (int i = 0; i < lines->size(); ++i) {
        std::vector<std::string> line = lines->at(i)->getInfo();
        for (int j = 0; j < line.size(); ++j) {
            if (j == line.size()-1) {
                std::cout << line[j];
            }
            else std::cout << line[j] << " ";
        }
        std::cout << std::endl;
    }
}

void TextEditor::initialize(){
    Helper::print("Welcome to the Text Editor by Jonathan Ginsburg.");
    std::string * menu = new std::string[mainMenuOptions];
    menu[0] = "1 for quitting.";
    menu[1] = "2 for opening a document.";
    menu[2] = "3 for saving the current document.";
    menu[3] = "4 for visualizing the current document.";
    menu[4] = "5 for free text editing.";
    menu[5] = "6 for inserting a line.";
    menu[6] = "7 for deleting a line.";
    menu[7] = "8 for inserting words at a line.";
    menu[8] = "9 for deleting words at a line.";
    bool keepRunning = true;
    while (keepRunning) {
        switch (Helper::menu("main", menu, mainMenuOptions)) {
            case 1:
                keepRunning = false;
                break;
            case 2:
                this->openDocument();
                break;
            case 3:
                this->saveDocument();
                break;
            case 4:
                this->visualizeDocument();
                break;
            case 5:
                this->freeTextEditing();
                break;
            case 6:
                this->insertLine();
                break;
            case 7:
                this->deleteLine();
                break;
            case 8:
                this->insertWords();
                break;
            case 9:
                this->deleteWords();
                break;
            default:
                Helper::print("Choice is not recognized");
                break;
        }
    }
}

void TextEditor::loadLines(){
    lines->clear();
    document.seekg(0);
    std::string line;
    if (document.is_open())
    {
        while ( getline (document,line) )
        {
            std::vector<std::string> splittedLine = split(line, ' ');
            lines->insertBack(splittedLine);
        }
        document.close();
    }
}

void TextEditor::openDocument(){
    Helper::print("Opening a document. All changes of the last opened file have been lost.");
    document.close();
    currentDocumentName = Helper::readLine("Enter the name of the document:");
    document.open(currentDocumentName, std::fstream::in | std::fstream::out | std::fstream::app);
    
    loadLines();
    
    Helper::print("Operation done.");
}

void TextEditor::saveDocument(){
    if (currentDocumentName == "No document.") {
        Helper::print("No name of document has been set. Proceeding to opening/creating a new document.");
        openDocument();
    }
    
    document.close();
    
    char myArray[currentDocumentName.size()+1];//as 1 char space for null is also required
    strcpy(myArray, currentDocumentName.c_str());
    std::remove(myArray);
    
    Helper::print("Saving document.");
    
    document.open(currentDocumentName, std::fstream::in | std::fstream::out | std::fstream::app);
    
    document.seekp(0);
    for (int i = 0; i < lines->size(); ++i) {
        std::vector<std::string> line = lines->at(i)->getInfo();
        for (int j = 0; j < line.size(); ++j) {
            if (j == line.size()-1) {
                document << line[j];
            }
            else document << line[j] << " ";
        }
        if (i != lines->size() - 1) {
            document << std::endl;
        }
    }
    document.flush();
    
    Helper::print("Operation done.");
}

void TextEditor::visualizeDocument(){
    std::string message = "Visualizing document: ";
    message.append(currentDocumentName);
    Helper::print(message);
    Helper::print("------------------------------------------------------------------");
    printDocument();
    Helper::print("------------------------------------------------------------------");
    Helper::print("Operation done.");
}

void TextEditor::freeTextEditing(){
    std::string message = "Free text editing of: ";
    message.append(currentDocumentName);
    message.append(" (Enter keyword killprocess to stop editing). New text will be appended to the old.");
    Helper::print(message);
    
    std::string line = Helper::readLineNoEndl();
    while (line != "killprocess") {
        std::vector<std::string> splittedLine = split(line, ' ');
        lines->insertBack(splittedLine);
        line = Helper::readLineNoEndl();
    }
    
    Helper::print("Operation done.");
}

void TextEditor::insertLine(){
    std::string message = "Inserting line to: ";
    message.append(currentDocumentName);
    Helper::print(message);
    
    std::string line = Helper::readLine("Enter line to insert: ");
    int position = Helper::read<int>("Enter the position of the new line. (first line is in position 1)");
    while (position < 1 || position > lines->size()) {
        position = Helper::read<int>("Position out of bounds. Enter the position of the new line. (first line is in position 1)");
    }
    
    std::vector<std::string> splittedLine = split(line, ' ');
    lines->insert(splittedLine, position-1);
    
    Helper::print("Operation done.");
}

void TextEditor::deleteLine(){
    std::string message = "Deleting line from: ";
    message.append(currentDocumentName);
    Helper::print(message);
    
    int position = Helper::read<int>("Enter the position of the line to delete. (first line is in position 1)");
    while (position < 1 || position > lines->size()) {
        position = Helper::read<int>("Position out of bounds. Enter the position of the line to delete. (first line is in position 1)");
    }
    
    delete lines->remove(position-1);
    
    Helper::print("Operation done.");
}

void TextEditor::insertWords(){
    std::string message = "Inserting words to: ";
    message.append(currentDocumentName);
    Helper::print(message);
    
    std::string words = Helper::readLine("Enter words to insert: ");
    int positionLine = Helper::read<int>("Enter the position of the line to which the words will be added. (first line is in position 1)");
    while (positionLine < 1 || positionLine > lines->size()) {
        positionLine = Helper::read<int>("Position out of bounds. Enter the position of the line to which the words will be added. (first line is in position 1)");
    }
    std::vector<std::string> line = lines->at(positionLine - 1)->getInfo();
    
    int positionWord = Helper::read<int>("Enter the position in which the new words will be added in the line. (first word is in position 1)");
    
    while (positionWord < 1 || positionWord > line.size()) {
        positionWord = Helper::read<int>("Position out of bounds. Enter the position in which the new words will be added in the line. (first word is in position 1)");
    }
    
    if (words != "") {
        std::vector<std::string> splittedWords = split(words, ' ');
        if (splittedWords.size() == 0) {
            splittedWords[0] = words;
        }
        lines->at(positionLine - 1)->setInfo(insertToVectorAtPosition(line, splittedWords, positionWord - 1));
    }
    
    Helper::print("Operation done.");
}

void TextEditor::deleteWords(){
    std::string message = "Deleting words from: ";
    message.append(currentDocumentName);
    Helper::print(message);
    
    int positionLine = Helper::read<int>("Enter the position of the line from which the words will be deleted. (first line is in position 1)");
    while (positionLine < 1 || positionLine > lines->size()) {
        positionLine = Helper::read<int>("Position out of bounds. Enter the position of the line from which the words will be deleted. (first line is in position 1)");
    }
    std::vector<std::string> line = lines->at(positionLine - 1)->getInfo();
    
    int positionWordFirst = Helper::read<int>("Enter the position of the first word to delete in the given line. (first word is in position 1)");
    
    while (positionWordFirst < 1 || positionWordFirst > line.size()) {
        positionWordFirst = Helper::read<int>("Position out of bounds. Enter the position of the first word to delete in the given line. (first word is in position 1)");
    }
    
    int positionWordSecond = Helper::read<int>("Enter the position of the last word to delete in the given line. (first word is in position 1)");
    
    while (positionWordSecond < positionWordFirst || positionWordSecond > line.size()) {
        positionWordSecond = Helper::read<int>("Position out of bounds. Enter the position of the last word to delete in the given line. (first word is in position 1)");
    }
    
    std::vector<std::string> temp;
    
    for (int i = 0; i < line.size(); ++i) {
        if (!(i >= positionWordFirst-1 && i <= positionWordSecond-1)) {
            temp.push_back(line[i]);
        }
    }
    
    lines->at(positionLine - 1)->setInfo(temp);
    
    Helper::print("Operation done.");
}