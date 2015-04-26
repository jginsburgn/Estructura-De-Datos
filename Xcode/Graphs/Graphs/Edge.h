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
    
public:
    
    Edge() {};
    
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
        destination = newDestination;
    }
    
    void setOrigin(Vertex<V, E> * newOrigin){
        origin = newOrigin;
    }
    
    friend std::ostream & operator << (std::ostream & os, const Edge<V, E> & edge){
        os << "Road's longitude: " << *edge.getInfo() << "; connecting: ";
        if (edge.getOrigin()) os << *edge.getOrigin();
        else os << "(NULL)";
        os << " --> ";
        if (edge.getDestination()) os << *edge.getDestination();
        else os << "(NULL)";
        return os;
    }
    
};

#endif
