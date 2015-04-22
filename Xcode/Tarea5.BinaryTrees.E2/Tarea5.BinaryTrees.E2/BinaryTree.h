//
//  BinaryTree.h
//  BinaryTree
//
//  Created by Vicente Cubells Nonell on 06/04/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef BinaryTree_BinaryTree_h
#define BinaryTree_BinaryTree_h

#include "BNode.h"
#include <vector>

namespace vcn {

    template <class T>
    class BinaryTree {
    private:
        BNode<T> * root = nullptr;
        
    public:
        BinaryTree() {}
        virtual ~BinaryTree();
        
        BinaryTree<T> * copy() const;
        BNode<T> * copy(const BNode<T> * node) const;
        BinaryTree<T> * newSubtree(const BNode<T> * node) const;
        
        bool empty();
        
        void clear();
        void clear(BNode<T> * node);
        
        BNode<T> * getRoot() const;
        void setRoot(BNode<T> * node);
        
        bool insert(BNode<T> * parent, T value);
        bool insert(BNode<T> * parent, BNode<T> * value);
        
        void printPreOrder() const;
        void printPreOrder(BNode<T> * node) const;
        
        void preOrder(void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *>) const;
        void preOrder(BNode<T> * node, void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *>) const;
        
        void printInOrder() const;
        void printInOrder(BNode<T> * node) const;
        
        void inOrder(void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *>) const;
        void inOrder(BNode<T> * node, void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *>) const;
        
        void printPostOrder() const;
        void printPostOrder(BNode<T> * node) const;
        
        void postOrder(void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *>) const;
        void postOrder(BNode<T> * node, void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *>) const;
        
        void isLeaf() const;
        void isLeaf(BNode<T> * node) const;
        
        void ancestors(BNode<T> * node) const;
        
        bool areBrothers(BNode<T> * a, BNode<T> * b) const;
        
        int depth(BNode<T> * node) const;
        
        int level(BNode<T> * node);
        
        void reflect();
        
        bool isSymmetrical() const;
    };
    
    template <class T>
    BinaryTree<T>::~BinaryTree()
    {
        clear();
    }
    
    template <class T>
    BinaryTree<T> * BinaryTree<T>::copy() const{
        BinaryTree<T> * output = new BinaryTree<T>();
        BNode<T> * node = new BNode<T>();
        node = copy(this->getRoot());
        output->insert(nullptr, node);
        return output;
    }
    
    template <class T>
    BNode<T> * BinaryTree<T>::copy(const BNode<T> * node) const{
        if (node){
            BNode<T> * output = new BNode<T>();
            output->setInfo(node->getInfo());
            output->setRight(copy(node->getRight()));
            output->setLeft(copy(node->getLeft()));
            return output;
        }
        return nullptr;
    }
    
    template <class T>
    BinaryTree<T> * BinaryTree<T>::newSubtree(const BNode<T> * node) const{
        BinaryTree<T> * newTree = new BinaryTree<T>();
        newTree->setRoot(copy(node));
        return newTree;
    }
    
    template <class T>
    bool BinaryTree<T>::empty()
    {
        return root == nullptr;
    }
    
    template <class T>
    void BinaryTree<T>::clear()
    {
        clear(root);
    }
    
    template <class T>
    void BinaryTree<T>::clear(BNode<T> * node)
    {
        std::vector<void *> a;
        postOrder(node, [](BNode<T> * node, std::vector<void *> args){
            delete node;
        }, a);
    }
    
    template <class T>
    BNode<T> * BinaryTree<T>::getRoot() const
    {
        return root;
    }
    
    template <class T>
    void BinaryTree<T>::setRoot(BNode<T> * node)
    {
        if (!empty()) {
            node->setLeft(root);
            root->setParent(node);
            root = node;
        }
        else {
            root = node;
        }
    }
    
    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, T value)
    {
        BNode<T> * node = new BNode<T>(value);
        bool inserted = insert(parent, node);
        
        if (!inserted) delete node;
        
        return inserted;
    }
    
    template <class T>
    bool BinaryTree<T>::insert(BNode<T> * parent, BNode<T> * value)
    {
        bool inserted = false;
        
        if (empty() || !parent) {
            setRoot(value);
            inserted = true;
        }
        else {
            if (!parent->getLeft()) {
                parent->setLeft(value);
                value->setParent(parent);
                inserted = true;
            }
            else if (!parent->getRight()) {
                parent->setRight(value);
                value->setParent(parent);
                inserted = true;
            }
        }
        
        return inserted;
    }
    
    template <class T>
    void BinaryTree<T>::printPreOrder() const
    {
        printPreOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::printPreOrder(BNode<T> * node) const
    {
        std::vector<void *> a;
        preOrder([](BNode<T> * node, std::vector<void *> args){
            std::cout << *node << std::endl;
        }, a);
    }
    
    
    template <class T>
    void BinaryTree<T>::preOrder(void (*action)(BNode<T> *, std::vector<void *>), std::vector<void *> args) const{
        preOrder(root, action, args);
    }
    
    template <class T>
    void BinaryTree<T>::preOrder(BNode<T> * node, void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *> args) const{
        if (node) {
            action(node, args);
            
            preOrder(node->getLeft(), action, args);
            preOrder(node->getRight(), action, args);
        }
    }
    
    template <class T>
    void BinaryTree<T>::printInOrder() const{
        printInOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::printInOrder(BNode<T> * node) const{
        std::vector<void *> a;
        inOrder([](BNode<T> * node, std::vector<void *> args){
            std::cout << *node << std::endl;
        }, a);
    }
    
    template <class T>
    void BinaryTree<T>::inOrder(void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *> args) const{
        inOrder(root, action, args);
    }
    
    template <class T>
    void BinaryTree<T>::inOrder(BNode<T> * node, void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *> args) const{
        if (node) {
            inOrder(node->getLeft(), action, args);
            
            action(node, args);
            
            inOrder(node->getRight(), action, args);
        }
    }
    
    template <class T>
    void BinaryTree<T>::printPostOrder() const{
        printPostOrder(root);
    }
    
    template <class T>
    void BinaryTree<T>::printPostOrder(BNode<T> * node) const{
        std::vector<void *> a;
        postOrder([](BNode<T> * node, std::vector<void *> args){
            std::cout << *node << std::endl;
        }, a);
    }
    
    template <class T>
    void BinaryTree<T>::postOrder(void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *> args) const{
        postOrder(root, action, args);
        
    }
    
    template <class T>
    void BinaryTree<T>::postOrder(BNode<T> * node, void (*action)(BNode<T> * , std::vector<void *>), std::vector<void *> args) const{
        if (node) {
            postOrder(node->getLeft(), action, args);
            postOrder(node->getRight(), action, args);
            
            action(node, args);
        }
    }
    
    template <class T>
    void BinaryTree<T>::isLeaf() const
    {
        isLeaf(root);
    }
    
    template <class T>
    void BinaryTree<T>::isLeaf(BNode<T> * node) const
    {
        if (node) {
            if (!node->getLeft() && !node->getRight()) {
                std::cout << *node << std::endl;
            }
            else {
                isLeaf(node->getLeft());
                isLeaf(node->getRight());
            }
        }
    }
    
    template <class T>
    void BinaryTree<T>::ancestors(BNode<T> * node) const
    {
        if (node) {
            std::cout << *node << " -> ";
            ancestors(node->getParent());
        }
    }
    
    template <class T>
    bool BinaryTree<T>::areBrothers(BNode<T> * a, BNode<T> * b) const{
        if (a && b) {
            return a->getParent() ==  b->getParent();
        }
        return false;
    }
    
    template <class T>
    int BinaryTree<T>::depth(BNode<T> *node) const{
        int retVal = 0;
        BNode<T> * tmp = node->getParent();
        while (tmp!=nullptr) {
            retVal++;
            tmp = tmp->getParent();
        }
        return retVal;
    }
    
    template <class T>
    int BinaryTree<T>::level(BNode<T> *node){
        int * height = new int();
        *height = 0;
        int * maxDepth = new int();
        *maxDepth = 0;
        std::vector<void *> args;
        args.push_back(maxDepth);
        args.push_back(this);
        preOrder([](BNode<T> * node, std::vector<void *> args){
            if (*(int *)args[0] < ((BinaryTree<T> *)args[1])->depth(node)) {
                *(int *)args[0]= ((BinaryTree<T> *)args[1])->depth(node);
            }
        }, args);
        *height = *maxDepth + 1;
        int returner = *height - depth(node);
        delete height;
        delete maxDepth;
        return returner;
    }
    
    template <class T>
    void BinaryTree<T>::reflect(){
        std::vector<void *> args;
        this->preOrder([](BNode<T> * node, std::vector<void *> args){
            BNode<T> * tmp = nullptr;
            if (node->getRight() && node->getLeft()) {
                tmp = node->getLeft();
                node->setLeft(node->getRight());
                node->setRight(tmp);
            }
        }, args);
    }
    
    template <class T>
    bool BinaryTree<T>::isSymmetrical() const{
        if (!this->empty()) {
            if (root->getLeft() && root->getRight()) {
                BinaryTree<T> * leftSubtree = new BinaryTree<T>();
                BinaryTree<T> * rightSubtree = new BinaryTree<T>();
                leftSubtree->setRoot(copy(root->getLeft()));
                rightSubtree->setRoot(copy(root->getRight()));
                return true;
            }
            else if (!root->getLeft() && !root->getRight()){
                return true;
            }
            return false;
        }
        return true;
    }
 
}

#endif
