//
//  main.cpp
//  EF.E2.Alfombra
//
//  Created by Jonathan Ginsburg on 5/12/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Helper.h"
#include "BinaryTree.h"
#include <sstream>
#include <string>

using namespace vcn;

BNode<std::string> * buildFromPAIOrder(std::string preOrder, std::string inOrder) {
    if (preOrder == "") {
        return nullptr;
    }
    std::stringstream ss;
    std::string info = "";
    char c = ((char*)preOrder.c_str())[0];
    ss << c;
    ss >> info;
    std::string newPreOrder = Helper::split(preOrder, info.c_str()[0])[1];
    std::string leftInOrder = Helper::split(inOrder, info.c_str()[0])[0];
    std::string rightInOrder = Helper::split(inOrder, info.c_str()[0])[1];
    int left = (int)leftInOrder.length();
    std::string leftPreOrder = "";
    std::string rightPreOrder =  "";
    for (int i = 0; i < left; ++i) {
        std::stringstream ss;
        std::string s;
        char c = newPreOrder.c_str()[i];
        ss << c;
        ss >> s;
        leftPreOrder.append(s);
        
    }
    for (int i = left; i < newPreOrder.length(); ++i) {
        std::stringstream ss;
        std::string s;
        char c = newPreOrder.c_str()[i];
        ss << c;
        ss >> s;
        rightPreOrder.append(s);
    }
    BNode<std::string> * retVal = new BNode<std::string>(info);
    retVal->setLeft(buildFromPAIOrder(leftPreOrder, leftInOrder));
    retVal->setRight(buildFromPAIOrder(rightPreOrder, rightInOrder));
    return retVal;
}

int main(int argc, const char * argv[]) {
    std::string preOrder = "GEAIBMCLDFKJH";
    std::string inOrder = "IABEGLDCFMKHJ";
    BinaryTree<std::string> btree;
    btree.setRoot(buildFromPAIOrder(preOrder, inOrder));
    btree.printInOrder();
    std::cout << std::endl;
    btree.printPreOrder();
    return 0;
}
