//
//  main.cpp
//  Tarea5.BinaryTrees.E1
//
//  Created by Jonathan Ginsburg on 4/20/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"

using namespace vcn;

BinaryTree<int> * descendentAdditions(BinaryTree<int> * a){
    BinaryTree<int> * b = a->copy(a);
    std::vector<void *> args;
    args.push_back(b);
    b->preOrder([](BNode<int> * node, std::vector<void *> args){
        
        int * sonsAddition = new int();
        *sonsAddition = 0;
        
        std::vector<void *> args2;
        
        args2.push_back(sonsAddition);
        ((BinaryTree<int> *)args[0])->preOrder(node, [](BNode<int> * node2, std::vector<void *> args2){
            (*((int *)args2[0])) += node2->getInfo();
        }, args2);
        
        node->setInfo(*sonsAddition);
        
        delete sonsAddition;
    }, args);
    return b;
}

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
    
    std::cout << "Printing tree preorder:" << std::endl;
    bt->printPreOrder();
    
    BinaryTree<int> * newBt = descendentAdditions(bt);
    std::cout << "\n\n\n" << std::endl;
    
    std::cout << "Printing descendentsadditiontree preorder:" << std::endl;
    newBt->printPreOrder();
    
    delete newBt;
    delete bt;
    return 0;
}
