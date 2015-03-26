//
//  DoubleCircularLinkedList.h
//  Tarea4.Listas.Ejercicio3
//
//  Created by Jonathan Ginsburg on 3/24/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Tarea4_Listas_Ejercicio3_DoubleCircularLinkedList_h
#define Tarea4_Listas_Ejercicio3_DoubleCircularLinkedList_h

#include "LinkedList.h"

using namespace vcn;

template <class T>
class DoubleCircularLinkedList :  public LinkedList<T> {
    
protected:
    
    Node<T> * _last = nullptr;
    
public:
    DoubleCircularLinkedList() {}
    virtual ~DoubleCircularLinkedList();
    
    /* Obtener un apuntador al último elemento */
    virtual Node<T> * last();
    
    /* Insertar un elemento nuevo */
    void insert(Node<T> *, int) override;
    
    /* Eliminar un elemento y regresar un apuntador al mismo.
     * Nota: No liberan la memmoria ocupada por el nodo eliminado
     */
    Node<T> * remove(int) override;
    
    /* Insertar un elemento nuevo */
    virtual void insert(T, int) override;
    virtual void insertFront(T) override;
    virtual void insertFront(Node<T> *) override;
    virtual void insertBack(T) override;
    virtual void insertBack(Node<T> *) override;
    
    /* Eliminar un elemento y regresar un apuntador al mismo.
     * Nota: No liberan la memmoria ocupada por el nodo eliminado
     */
    virtual Node<T> *  removeFront() override;
    virtual Node<T> *  removeBack() override;
    virtual Node<T> * remove(Node<T> *) override;
    
    /* Eliminar todos los elementos de la lista y liberar la memoria ocupada
     * por los mismos.
     */
    void clear() override;
    
    /* Obtener el elemento que se encuentra en una posición */
    Node<T> * at(int) override;
    
    /* Mostrar el contenido de la lista */
    template <typename Tn>
    friend std::ostream & operator <<(std::ostream &, DoubleCircularLinkedList<Tn> &);
    
};

template <class T>
DoubleCircularLinkedList<T>::~DoubleCircularLinkedList()
{
    this->clear();
}

template <class T>
Node<T> * DoubleCircularLinkedList<T>::last()
{
    return this->_last;
}

template  <class T>
void DoubleCircularLinkedList<T>::insert(Node<T> * newnode, int position)
{
    /* Cuando la lista está vacía */
    if ( this->empty() ) {
        this->_first = this->_last = newnode;
        newnode->setNext(this->_first);
        newnode->setPrevious(this->_first);
    }
    /* Cuando position < 0 */
    else if (position <= 0) {
        newnode->setNext(this->_first);
        newnode->setPrevious(this->_last);
        this->_first->setPrevious(newnode);
        this->_first = newnode;
        this->_last->setNext(this->_first);
    }
    
    /* Cuando se inserta en cualquier posición diferente del inicio */
    else {
        
        if (position > this->_size) { position = this->_size; }
        
        Node<T> * tmp1 = this->at(position-1);
        Node<T> * tmp2 = tmp1->getNext();
        
        newnode->setNext(tmp2);
        newnode->setPrevious(tmp1);
        
        tmp1->setNext(newnode);
        tmp2->setPrevious(newnode);
        
        if (position == this->_size) {
            this->_last = newnode;
        }
    }
    
    /* Incrementar el tamaño de la lista */
    ++this->_size;
}

template <typename T>
void DoubleCircularLinkedList<T>::insert(T info, int position){
    Node<T> * newNode = new Node<T>();
    newNode->setInfo(info);
    this->insert(newNode, position);
}

template <typename T>
void DoubleCircularLinkedList<T>::insertFront(T info){
    this->insert(info, 0);
}

template <typename T>
void DoubleCircularLinkedList<T>::insertFront(Node<T> * newNode){
    this->insert(newNode, 0);
}

template <typename T>
void DoubleCircularLinkedList<T>::insertBack(T info){
    this->insert(info, this->size());
}

template <typename T>
void DoubleCircularLinkedList<T>::insertBack(Node<T> * newNode){
    this->insert(newNode, this->size());
}

template  <class T>
Node<T> * DoubleCircularLinkedList<T>::remove(int position)
{
    /* Cuando la lista está vacía o position es inválida */
    if (this->empty() || (position < 0 || position >= this->_size )) {
        return nullptr;
    }
    
    Node<T> * removenode;
    
    /* Eliminar el primer nodo de la lista */
    if (position == 0) {
        removenode = this->_first;
        this->_first = this->_first->getNext();
        this->_first->setPrevious(this->_last);
        this->_last->setNext(this->_first);
        
        /* Caso particular en que existe un único elemento */
        if (this->_size == 1) {
            this->_first = this->_last = nullptr;
        }
        
    }
    /* Eliminar cualquier otro nodo */
    else {
        Node<T> * prev = this->at(position-1);
        removenode = prev->getNext();
        prev->setNext(removenode->getNext());
        removenode->getNext()->setPrevious(prev);
        
        /* Caso particular en que se elimina el último */
        if (position == this->_size -1) {
            this->_last = prev;
        }
    }
    
    /* Establecer el siguiente en nullptr */
    removenode->setNext(nullptr);
    removenode->setPrevious(nullptr);
    
    /* Decrementar el tamaño de la lista */
    --this->_size;
    
    return removenode;
}

template  <class T>
Node<T> * DoubleCircularLinkedList<T>::removeFront(){
    return this->remove(0);
}

template  <class T>
Node<T> * DoubleCircularLinkedList<T>::removeBack(){
    return this->remove(this->size()-1);
}

template  <class T>
Node<T> * DoubleCircularLinkedList<T>::remove(Node<T> * removeNode){
    return this->remove(this->LinkedList<T>::at(removeNode));
}

template  <class T>
Node<T> *  DoubleCircularLinkedList<T>::at(int position)
{
    /* Cuando la lista está vacía o position es inválida */
    if (this->empty() || (position < 0 || position >= this->_size )) {
        return nullptr;
    }
    
    /*  Buscar el nodo que se encuentra en position */
    int pos = 0;
    Node<T> * tmp = this->_first;
    
    while (pos++ < position)
    {
        tmp = tmp->getNext();
    }
    
    return tmp;
    
}

template  <class T>
void DoubleCircularLinkedList<T>::clear()
{
    /* Cuando la lista está vacía */
    if ( this->empty() ) { return; }
    
    Node<T> * tmp = this->_first;
    
    while (tmp != this->_last) {
        this->_first = this->_first->getNext();
        this->_last->setNext(this->_first);
        
        delete tmp;
        tmp = this->_first;
    }
    
    /* Para elimiinar el último elemento */
    delete tmp;
    tmp = this->_first;
    
    this->_size = 0;
    
    this->_first = this->_last = nullptr;
}

template <class T>
std::ostream & operator <<(std::ostream & os, DoubleCircularLinkedList<T> & list)
{
    for (auto node : list )
    {
        os << node << std::endl;
    }
    
    /*
     
     Node<T> * inicio = list.begin();
     Node<T> * fin = list.end();
     
     for (auto it = inicio; it != fin; ++it)
     {
     os << *it;
     }
     
     */
    
    return os;
}


#endif
