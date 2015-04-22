//
//  main.cpp
//  EjerciciosDeArboles
//
//  Created by Jonathan Ginsburg on 4/13/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    using namespace vcn;
    
    BinaryTree<int> * bt = new BinaryTree<int>();
    bt->insert(nullptr, 10);
    BNode<int> * tmp = bt->getRoot();
    bt->insert(tmp, 5);
    bt->insert(tmp, 6);
    tmp = tmp->getLeft();
    bt->insert(tmp, 4);
    bt->insert(tmp, 6);
    tmp = tmp->getRight();
    bt->insert(tmp, 7);
    bt->insert(tmp, 8);
    tmp = tmp->getParent();
    tmp = tmp->getLeft();
    bt->insert(tmp, 2);
    bt->insert(tmp, 1);
    tmp = tmp->getRight();
    bt->insert(tmp, 3);
    bt->insert(tmp, 2);
    tmp = tmp->getRight();
    bt->insert(tmp, 12);
    tmp = bt->getRoot();
    tmp = tmp->getRight();
    bt->insert(tmp, 9);
    tmp = tmp->getLeft();
    bt->insert(tmp, 10);
    
    bt->printPostOrder();
    
    tmp = bt->getRoot();
    tmp = tmp->getLeft();
    tmp = tmp->getLeft();
    tmp = tmp->getRight();
    tmp = tmp->getRight();
    tmp = tmp->getLeft();
    std::cout << bt->level(tmp) << std::endl;
    
    delete bt;
    return 0;
}
