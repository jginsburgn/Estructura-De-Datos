//
//  Graph.h
//  Graphs
//
//  Created by Jonathan Ginsburg on 4/26/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef Graphs_Graph_h
#define Graphs_Graph_h

#include "Edge.h"

template <class V, class E>
class Graph{
    
private:
    
    std::vector<Vertex<V, E> *> * vertices = new std::vector<Vertex<V, E> *>();
    std::vector<Edge<V, E> *> * edges = new std::vector<Edge<V, E> *>();
    
public:
    
    Graph() {};
    
    ~Graph() {
        for (int i = 0; i < vertices->size(); ++i) {
            delete (*vertices)[i];
        }
        delete vertices;
        vertices = nullptr;
        
        for (int i = 0; i < edges->size(); ++i) {
            delete (*edges)[i];
        }
        delete edges;
        edges = nullptr;
        
    }
    
    void addVertex(V info){
        for (int i = 0; i < vertices->size(); ++i) {
            if (info == *((*vertices)[i]->getInfo())) {
                throw "City already exists...";
            }
        }
        Vertex<V, E> * newVertex = new Vertex<V, E>(info);
        vertices->push_back(newVertex);
    }
    
    void addEdge(E info, V origin, V destination){
        for (int i = 0; i < edges->size(); ++i) {
            if (*((*edges)[i]->getOrigin())->getInfo() == origin) {
                if (*((*edges)[i]->getDestination())->getInfo() == destination) {
                    throw "Road already exists...";
                }
            }
        }
        
        Vertex<V, E> * originVertex = nullptr;
        Vertex<V, E> * destinationVertex = nullptr;
        
        for (int i = 0; i < vertices->size(); ++i) {
            if (*((*vertices)[i])->getInfo() == origin) {
                originVertex = (*vertices)[i];
            }
            if (*((*vertices)[i])->getInfo() == destination) {
                destinationVertex = (*vertices)[i];
            }
        }
        Edge<V, E> * newEdge = new Edge<V, E>(info, originVertex, destinationVertex);
        edges->push_back(newEdge);
    }
    
    std::vector<Vertex<V, E> *> * getVertices() const{
        return vertices;
    }
    
    std::vector<Edge<V, E> *> * getEdges() const{
        return edges;
    }
    
    Vertex<V, E> * getVertex(V info) const{
        Vertex<V, E> * returner = nullptr;
        for (int i = 0; i < vertices->size(); ++i) {
            if (info == *(*vertices)[i]->getInfo()) {
                returner = (*vertices)[i];
            }
        }
        if (!returner) {
            throw "No city with that name...";
        }
        return returner;
    }
    
    Edge<V, E> * getEdge(E info) const{
        Edge<V, E> * returner = nullptr;
        for (int i = 0; i < edges->size(); ++i) {
            if (info == (*edges)[i]->getInfo()) {
                returner = (*edges)[i];
            }
        }
        if (!returner) {
            throw "No road with that name...";
        }
        return returner;
    }
    
    Vertex<V, E> * getVertexAt(int i) const{
        return (*vertices)[i];
    }
    
    Edge<V, E> * getEdgeAt(int i) const{
        return (*edges)[i];
    }
    
    friend std::ostream & operator << (std::ostream & os, const Graph<V, E> & graph){
        os << "Vertices: " << std::endl;
        for (int i = 0; i < graph.vertices->size(); ++i) {
            os << "\t" << i+1 << ") " << *(*graph.vertices)[i] << "." << std::endl;
        }
        os << "Edges: " << std::endl;
        for (int i = 0; i < graph.edges->size(); ++i) {
            os << "\t" << i+1 << ") " << *(*graph.edges)[i] << "." << std::endl;
        }
        return os;
    }
};

#endif
