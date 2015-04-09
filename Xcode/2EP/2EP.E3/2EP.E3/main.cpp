//
//  main.cpp
//  2EP.E3
//
//  Created by Jonathan Ginsburg on 4/9/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "LinkedList.h"
#include "Stack.h"
#include <vector>
#include <stack>

using namespace vcn;

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

LinkedList<int> * productOf(LinkedList<int> * N, LinkedList<int> * M){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < M->size(); ++i) {
        for (int j = 0; j < N->size(); ++j) {
            p->insertBack(M->at(i)->getInfo()*N->at(j)->getInfo());
        }
    }
    return p;
}

LinkedList<int> * intersectionOf(LinkedList<int> * M, LinkedList<int> * N){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < M->size(); ++i) {
        for (int j = 0; j < N->size(); ++j) {
            if (M->at(i)->getInfo() == N->at(j)->getInfo()) {
                p->insertBack(M->at(i)->getInfo());
            }
        }
    }
    return p;
}

LinkedList<int> * subtractionOf(LinkedList<int> * M, LinkedList<int> * N){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < M->size(); ++i) {
        bool repeated = false;
        for (int j = 0; j < N->size(); ++j) {
            if (M->at(i)->getInfo() == N->at(j)->getInfo()) {
                repeated = true;
                break;
            }
        }
        if (!repeated) {
            p->insertBack(M->at(i)->getInfo());
        }
    }
    return p;
}

LinkedList<int> * unionOf(LinkedList<int> * N, LinkedList<int> * M){
    LinkedList<int> * p = new LinkedList<int>();
    for (int i = 0; i < N->size(); ++i) {
        p->insertBack(N->at(i)->getInfo());
    }
    for (int i = 0; i < M->size(); ++i) {
        bool repeated = false;
        for (int j = 0; j < N->size(); ++j) {
            if (N->at(j)->getInfo() == M->at(i)->getInfo()) repeated = true;
        }
        if (!repeated) {
            p->insertBack(M->at(i)->getInfo());
        }
    }
    return p;
}

bool isMathInitialDelimiter(char c){
    switch (c) {
        case '(':
            return true;
            break;
        case '{':
            return true;
            break;
        case '[':
            return true;
            break;
        default:
            return false;
            break;
    }
}

bool isMathFinalDelimiter(char c){
    switch (c) {
        case ')':
            return true;
            break;
        case '}':
            return true;
            break;
        case ']':
            return true;
            break;
        default:
            return false;
            break;
    }
}

char closerForOpener(char c){
    switch (c) {
        case '(':
            return ')';
            break;
        case '{':
            return '}';
            break;
        case '[':
            return ']';
            break;
        default:
            return ')';
            break;
    }
}

bool isSet(std::string expression){
    const char * asdf = expression.c_str();
    return asdf[0]=='{' && asdf[expression.length()-1]=='}';
}

LinkedList<int> * setFromExpression(std::string expression){
    std::vector<std::string> numbers = split(expression, ',');
    LinkedList<int> * set = new LinkedList<int>();
    for (int i = 0; i < numbers.size(); ++i) {
        if (i==0) {
            int num = atoi(split(numbers[0], '{')[1].c_str());
            set->insertFront(num);
        }
        else if (i==numbers.size()-1){
            int num = atoi(split(numbers[i], '}')[0].c_str());
            set->insertFront(num);
        }
        else{
            int num = atoi(numbers[i].c_str());
            set->insertFront(num);
        }
    }
    return set;
}

LinkedList<int> * parseExpression(std::string expression){
    if (isSet(expression)) {
        return setFromExpression(expression);
    }
    else{
        const char * charMathEquation = expression.c_str();
        std::vector<std::string> subExpressions;
        std::string subExpression = "";
        for (int i = 0; i < expression.length(); ++i) {
            char currentChar = charMathEquation[i];
            if (isMathInitialDelimiter(currentChar)) {
            }
            else if (isMathFinalDelimiter(currentChar)){

            }
        }
    }
}


int main(int argc, const char * argv[]) {
    std::string expression = Helper::read<std::string>("Enter an expresssion:");
    std::vector<std::string> splitplus = split(expression, '+');
    for (int i = 0; i < splitplus.size(); ++i) {
        Helper::print(splitplus[i]);
    }
    return 0;
}
