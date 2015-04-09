//
//  StackB.h
//  StackB
//
//  Created by Vicente Cubells Nonell on 19/03/15.
//  Copyright (c) 2015 Vicente Cubells Nonell. All rights reserved.
//

#ifndef StackB_StackB_h
#define StackB_StackB_h

#include "LinkedListB.h"

namespace vcn {
template <class T>
class StackB : private LinkedListB<T> {
public:
    StackB();
    virtual ~StackB();
    
    int size();
    bool empty();
    
    Node<T> * top();
    Node<T> * pop();
    void push(T);
    void push(Node<T> *);
    
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream &, StackB<Tn> &);
};

template <class T>
StackB<T>::StackB() : LinkedListB<T>()
{
}

template <class T>
StackB<T>::~StackB()
{
    this->clear();
}

template <class T>
int StackB<T>::size()
{
    return LinkedListB<T>::size();
}

template <class T>
bool StackB<T>::empty()
{
    return LinkedListB<T>::empty();
}

template <class T>
Node<T> * StackB<T>::top()
{
    return this->first();
}

template <class T>
Node<T> * StackB<T>::pop()
{
    return this->removeFront();
}

template <class T>
void StackB<T>::push(T value)
{
    this->insertFront(value);
}

template <class T>
void StackB<T>::push(Node<T> * node)
{
    this->insertFront(node);
}

template <class T>
std::ostream & operator <<(std::ostream & os, StackB<T> & StackB)
{
    for (auto i : StackB) {
        os << i << std::endl;
    }
    
    return os;
}

}
#endif
