//
//  Edge.h
//  Graphs
//
//  Created by Jonathan Ginsburg on 4/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Graphs_Edge_h
#define Graphs_Edge_h

#include "Vertex.h"

template <typename V, typename E>
class Edge{
    
private:
    
    E * info = new E();
    Vertex<V, E> * origin = nullptr;
    Vertex<V, E> * destination = nullptr;
    
    void copy(const Edge<V, E> & source){
        *info = *source.getInfo();
        origin = source.getOrigin();
        destination = source.getDestination();
    }
    
public:
    
    Edge() {};
    
    Edge(const Edge<V, E> & source){
        copy(source);
    }
    
    Edge(E newInfo){
        setInfo(newInfo);
    }
    
    Edge(Vertex<V, E> * newOrigin, Vertex<V, E> * newDestination){
        setOrigin(newOrigin);
        setDestination(newDestination);
    }
    
    Edge(E newInfo, Vertex<V, E> * newOrigin, Vertex<V, E> * newDestination){
        setInfo(newInfo);
        setOrigin(newOrigin);
        setDestination(newDestination);
    }
    
    ~Edge() {
        if (origin) {
            origin->disconnectEdge(this);
        }
        if (destination) {
            destination->disconnectEdge(this);
        }
        delete info;
    }
    
    E * getInfo() const {
        return info;
    }
    
    Vertex<V, E> * getOrigin() const {
        return origin;
    }
    
    Vertex<V, E> * getDestination() const {
        return destination;
    }
    
    void setInfo(E newInfo){
        *info = newInfo;
    }
    
    void setDestination(Vertex<V, E> * newDestination){
        if (destination != newDestination) {
            if (destination) {
                destination->disconnectEdge(this);
            }
            destination = newDestination;
        }
    }
    
    void setOrigin(Vertex<V, E> * newOrigin){
        if (origin != newOrigin) {
            if (origin) {
                origin->disconnectEdge(this);
            }
            origin = newOrigin;
        }
    }
    
    Edge<V, E> & operator = (const Edge<V, E> & source){
        copy(source);
        return *this;
    }
    
    bool operator == (Edge<V, E> & edge) const {
        return *origin == *edge.getOrigin() && *destination == *edge.getDestination() && *info == *edge.getInfo();
    }
    
    friend std::ostream & operator << (std::ostream & os, const Edge<V, E> & edge){
        os << "Edge's info: " << *edge.getInfo() << "; connecting: ";
        if (edge.getOrigin()) os << *edge.getOrigin();
        else os << "(NULL)";
        os << " --> ";
        if (edge.getDestination()) os << *edge.getDestination();
        else os << "(NULL)";
        return os;
    }
};

#endif
