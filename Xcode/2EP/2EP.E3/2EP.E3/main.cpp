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
#include "StackB.h"
#include <vector>
#include <stack>

struct parenthesis {
    int initial;
    int final;
};

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
//        case '{':
//            return true;
//            break;
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
//        case '}':
//            return true;
//            break;
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
//        case '{':
//            return '}';
//            break;
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
    bool noOperators = true;
    for (int i = 0; i < expression.length(); ++i) {
        if (asdf[i]=='+' || asdf[i]=='*' || isMathFinalDelimiter(asdf[i]) || isMathInitialDelimiter(asdf[i])) {
            noOperators = false;
        }
    }
    return asdf[0]=='{' && asdf[expression.length()-1]=='}' && noOperators;
}

LinkedList<int> * setFromExpression(std::string expression){
    std::vector<std::string> numbers = split(expression, ',');
    LinkedList<int> * set = new LinkedList<int>();
    for (int i = 0; i < numbers.size(); ++i) {
        if (i==0) {
            int num = atoi(numbers[0].substr(1).c_str());
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

parenthesis positionOfParenthesis(std::string expression){
    using namespace vcn;
    
    parenthesis returner;
    bool initialset = false;
    bool finalset = false;
    StackB<char> * parentheses = new StackB<char>();
    const char * charMathEquation = expression.c_str();
    
    for (int i = 0; i < expression.length(); ++i) {
        char currentChar = charMathEquation[i];
        if (isMathInitialDelimiter(currentChar)) {
            parentheses->push(currentChar);
            if (!initialset) {
                returner.initial = i;
                initialset=true;
            }
        }
        else if (isMathFinalDelimiter(currentChar)){
            Node<char> * currentNode = parentheses->pop();
            if (closerForOpener(currentNode->getInfo())==currentChar) {
                delete currentNode;
                if (parentheses->empty() && !finalset) {
                    returner.final = i;
                    finalset=true;
                }
            }
            else {
                std::cout << "The equation is not balanced." << std::endl;
            }
        }
    }
    return returner;
}

LinkedList<int> * parseExpression(std::string expression){
    if (isSet(expression)) {
        return setFromExpression(expression);
    }
    else{
        std::string tmp = expression;
        std::vector<parenthesis> parentheses;
        std::vector<std::string> subexpressions;
        int p = 0;
        while (!isSet(tmp)) {
            parentheses.push_back(positionOfParenthesis(tmp));
            if (parentheses[p].final+2 > tmp.length()-1) {
                tmp = "{}";
            }
            else tmp = tmp.substr(parentheses[p].final+2);
            p++;
        }
    }
    return nullptr;
}


int main(int argc, const char * argv[]) {
    std::string fd = "{}+{}*({}+({}*{})*{})+({}+{})";
    parenthesis  p = positionOfParenthesis(fd);
    Helper::print(Helper::intToString(p.initial));
    Helper::print(Helper::intToString(p.final));
    Helper::print(fd.substr(p.initial + 1 , p.final-p.initial-1));
    LinkedList<int> * ll = parseExpression(Helper::read<std::string>("Enter expression:"));
    std::cout << *ll << std::endl;
    return 0;
}
