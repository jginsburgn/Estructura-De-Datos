//
//  Vertex.h
//  Graphs
//
//  Created by Jonathan Ginsburg on 4/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Graphs_Vertex_h
#define Graphs_Vertex_h

#include <iostream>
#include <vector>

template <typename V, typename E>
class Edge;

template <typename V, typename E>
class Vertex{
    
private:
    
    V * info = new V();
    std::vector<Edge<V, E> *> * edges = new std::vector<Edge<V, E> *>();
    std::vector<Edge<V, E> *> * outgoingEdges = new std::vector<Edge<V, E> *>();
    
public:
    
    Vertex();
    
    Vertex(V newInfo) {
        *info = newInfo;
    }
    
    ~Vertex() {
        delete edges;
        edges = nullptr;
        delete outgoingEdges;
        outgoingEdges = nullptr;
        delete info;
        info = nullptr;
    }
    
    V * getInfo() const{
        return info;
    }
    std::vector<Edge<V, E> *> * getEdges() const{
        return edges;
    }
    
    void setInfo(V newInfo){
        *info = newInfo;
    }
    
    void connectIncomingEdge(Edge<V, E> * edge) {
        bool shouldInsert = true;
        for (int i = 0; i < edges->size(); ++i) {
            if ((*edges)[i] == edge) {
                shouldInsert = false;
                edge->setDestination(this);
            }
        }
        if (shouldInsert) {
            edge->setDestination(this);
            edges->push_back(edge);
        }
    }
    
    void connectOutgoingEdge(Edge<V, E> * edge) {
        bool shouldInsert = true;
        for (int i = 0; i < edges->size(); ++i) {
            if ((*edges)[i] == edge) {
                shouldInsert = false;
                edge->setOrigin(this);
            }
        }
        if (shouldInsert) {
            edge->setOrigin(this);
            edges->push_back(edge);
            outgoingEdges->push_back(edge);
        }
    }
    
    void disconnectEdge(Edge<V, E> * edge){
        bool isConnected = false;
        bool outgoingEdge = false;
        for (int i = 0; i < edges->size(); ++i) {
            if ((*edges)[i] == edge) {
                edges->erase(edges->begin() + i);
                isConnected = true;
            }
        }
        for (int i = 0; i < outgoingEdges->size(); ++i) {
            if ((*outgoingEdges)[i] == edge) {
                outgoingEdges->erase(outgoingEdges->begin() + i);
                outgoingEdge = true;
                isConnected = true;
            }
        }
        if (!isConnected) return;
        if (outgoingEdge) edge->setOrigin(nullptr);
        else edge->setDestination(nullptr);
    }
    
    friend std::ostream & operator << (std::ostream & os, const Vertex<V, E> & vertex){
        os << *vertex.getInfo();
        return os;
    }
    
};

#endif
