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
    class OrderedLinkedList : private LinkedList<T>{
        bool (*ordering)(Node<T> * a, Node<T> * b);
    public:
        OrderedLinkedList();
        OrderedLinkedList(bool (*newOrdering)(Node<T> * a, Node<T> * b));
        static bool ascending(Node<T> * a, Node<T> * b);
        static bool descending(Node<T> * a, Node<T> * b);
        virtual void insert(T);
        virtual void insert(Node<T> *);
        
        /* parent methods that need to be republicized due to private inheritance*/
        Node<T> * first();
        int size() const;
        bool empty();
        
        Node<T> * remove(int);
        Node<T> *  removeFront();
        Node<T> *  removeBack();
        
        void clear();
        
        Node<T> *  at(int);
        int at(Node<T> *);
        
        template <typename Tn>
        friend std::ostream & operator <<(std::ostream &, LinkedList<Tn> &);
        
        Node<T> * operator [](const int);
    };
    
    template <class T>
    Node<T> * OrderedLinkedList<T>::first(){
        return LinkedList<T>::first();
    }
    template <class T>
    int OrderedLinkedList<T>::size() const{
        return LinkedList<T>::size();
    }
    
    template <class T>
    bool OrderedLinkedList<T>::empty(){
        return LinkedList<T>::empty();
    }
    
    template <class T>
    Node<T> * OrderedLinkedList<T>::remove(int position){
        return LinkedList<T>::remove(position);
    }
    
    template <class T>
    Node<T> * OrderedLinkedList<T>::removeFront(){
        return LinkedList<T>::removeFront();
    }
    
    template <class T>
    Node<T> * OrderedLinkedList<T>::removeBack(){
        return LinkedList<T>::removeBack();
    }
    
    template <class T>
    void OrderedLinkedList<T>::clear(){
        LinkedList<T>::clear();
    }
    
    template <class T>
    Node<T> * OrderedLinkedList<T>::at(int position){
        return LinkedList<T>::at(position);
    }
    
    template <class T>
    int OrderedLinkedList<T>::at(Node<T> * node){
        return LinkedList<T>::at(node);
    }
    
    template <typename Tn>
    std::ostream & operator <<(std::ostream & os , OrderedLinkedList<Tn> & ll){
        return LinkedList<Tn>::operator<<(os, ll);
    }
    
    template <typename T>
    Node<T> * OrderedLinkedList<T>::operator [](const int position){
        return LinkedList<T>::operator[](position);
    }
    
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
    
}

#endif
