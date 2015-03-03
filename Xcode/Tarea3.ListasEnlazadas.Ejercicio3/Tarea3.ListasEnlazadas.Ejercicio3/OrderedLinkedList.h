//
//  OrderedLinkedList.h
//  Tarea3.ListasEnlazadas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/3/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//


#ifndef Tarea3_ListasEnlazadas_Ejercicio3_OrderedLinkedList_h
#define Tarea3_ListasEnlazadas_Ejercicio3_OrderedLinkedList_h

#include "LinkedList.h"

namespace vcn {
    template <class T>
    class OrderedLinkedList : public LinkedList<T>{
        bool (*ordering)(Node<T> * a, Node<T> * b);
    public:
        OrderedLinkedList();
        OrderedLinkedList(bool (*newOrdering)(Node<T> * a, Node<T> * b));
        static bool ascending(Node<T> * a, Node<T> * b);
        static bool descending(Node<T> * a, Node<T> * b);
        virtual void insert(T);
        virtual void insert(Node<T> *);
        virtual void insert(T, int);
        virtual void insert(Node<T> *, int);
        virtual void insertFront(T);
        virtual void insertFront(Node<T> *);
        virtual void insertBack(T);
        virtual void insertBack(Node<T> *);
    };
    
    template <class T>
    OrderedLinkedList<T>::OrderedLinkedList() : LinkedList<T>() {
        ordering = OrderedLinkedList<T>::ascending;
    }
    template <class T>
    OrderedLinkedList<T>::OrderedLinkedList(bool (*newOrdering)(Node<T> * a, Node<T> * b)){
        ordering = newOrdering;
    }
    
    template <class T>
    bool OrderedLinkedList<T>::ascending(Node<T> *a, Node<T> *b){
        return *a > *b;
    }
    
    template <class T>
    bool OrderedLinkedList<T>::descending(Node<T> *a, Node<T> *b){
        return *a < *b;
    }
    
    template <class T>
    void OrderedLinkedList<T>::insert(T element){
        Node<T> * newNode = new Node<T>(element);
        insert(newNode);
    }
    
    
    template <class T>
    void OrderedLinkedList<T>::insert(Node<T> * newNode){
        Node<T> * tmp = this->first();
        int position = 0;
        while (tmp != nullptr && ordering(newNode, tmp)) {
            tmp = tmp->getNext();
            ++position;
        }
        LinkedList<T>::insert(newNode, position);
    }
    
    template <class T>
    void OrderedLinkedList<T>::insert(T element, int){
        insert(element);
    }
    
    template <class T>
    void OrderedLinkedList<T>::insert(Node<T> * newNode, int){
        insert(newNode);
    }
    
    template <class T>
    void OrderedLinkedList<T>::insertFront(T element){
        insert(element);
    }
    
    template <class T>
    void OrderedLinkedList<T>::insertFront(Node<T> * newNode){
        insert(newNode);
    }
    
    template <class T>
    void OrderedLinkedList<T>::insertBack(T element){
        insert(element);
    }
    
    template <class T>
    void OrderedLinkedList<T>::insertBack(Node<T> * newNode){
        insert(newNode);
    }
    
}

#endif
