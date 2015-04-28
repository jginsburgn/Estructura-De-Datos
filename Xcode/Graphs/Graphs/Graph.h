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
        
        Vertex<V, E> * originVertex = getVertex(origin);
        Vertex<V, E> * destinationVertex = getVertex(destination);
        Edge<V, E> * newEdge = new Edge<V, E>(info, originVertex, destinationVertex);
        
        for (int i = 0; i < vertices->size(); ++i) {
            if (*((*vertices)[i])->getInfo() == origin) {
                originVertex->connectOutgoingEdge(newEdge);
            }
            if (*((*vertices)[i])->getInfo() == destination) {
                destinationVertex->connectIncomingEdge(newEdge);
            }
        }
        edges->push_back(newEdge);
    }
    
    bool removeVertex(V info){
        int position = -1;
        Vertex<V, E> * vertexToDelete = nullptr;
        for (int i = 0; i < vertices->size(); ++i) {
            if (info == *((*vertices)[i]->getInfo())) {
                vertexToDelete = (*vertices)[i];
                position = i;
                break;
            }
        }
        if (vertexToDelete) {
            for (int i = 0; i < vertexToDelete->getEdges()->size() ; ++i) {
                Edge<V, E> * edgeToDelete = (*vertexToDelete->getEdges())[i];
                removeEdge(edgeToDelete);
                delete vertexToDelete;
                return true;
            }
        }
        return false;
    }
    
    bool removeVertex(Vertex<V, E> * vertexToDelete){
        int position = -1;
        for (int i = 0; i < vertices->size(); ++i) {
            if (*vertexToDelete->getInfo() == *((*vertices)[i]->getInfo())) {
                position = i;
                break;
            }
        }
        if (vertexToDelete) {
            for (int i = 0; i < vertexToDelete->getEdges()->size() ; ++i) {
                Edge<V, E> * edgeToDelete = (*vertexToDelete->getEdges())[i];
                if (removeEdge(edgeToDelete)) --i;
            }
            vertices->erase(vertices->begin() + position);
            delete vertexToDelete;
            return true;
        }
        return false;
    }
    
    bool removeEdge(Edge<V, E> * edgeToDelete){
        int position = -1;
        for (int i = 0; i < edges->size(); ++i) {
            if (*((*edges)[i])->getOrigin()->getInfo() == *(edgeToDelete->getOrigin()->getInfo())) {
                if (*((*edges)[i]->getDestination())->getInfo() == *(edgeToDelete->getDestination()->getInfo())) {
                    edgeToDelete = (*edges)[i];
                    position = i;
                    break;
                }
            }
        }
        if (edgeToDelete) {
            if (edgeToDelete->getOrigin()) {
                edgeToDelete->getOrigin()->disconnectEdge(edgeToDelete);
            }
            if (edgeToDelete->getDestination()) {
                edgeToDelete->getDestination()->disconnectEdge(edgeToDelete);
            }
            edges->erase(edges->begin() + position);
            delete edgeToDelete;
            return true;
        }
        return false;
    }
    
    bool removeEdge(E info, V origin, V destination){
        int position = -1;
        Edge<V, E> * edgeToDelete = nullptr;
        for (int i = 0; i < edges->size(); ++i) {
            if (*((*edges)[i]->getOrigin())->getInfo() == origin) {
                if (*((*edges)[i]->getDestination())->getInfo() == destination) {
                    edgeToDelete = (*edges)[i];
                    position = i;
                }
            }
        }
        return removeEdge(edgeToDelete);
    }
    
    void clear(){
        for (int i = 0; i < vertices->size(); ++i) {
            if (removeVertex((*vertices)[i])) --i;
        }
    }
    
    void disconnectAll() {
        while (edges->size() != 0) {
            removeEdge((*edges)[0]);
        }
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
                break;
            }
        }
        if (!returner) {
            throw "No city with that name...";
        }
        return returner;
    }
    
    Edge<V, E> * getEdge(V origin, V destination) const{
        Edge<V, E> * returner = nullptr;
        for (int i = 0; i < edges->size(); ++i) {
            if (origin == *(*edges)[i]->getOrigin()->getInfo() && destination == *(*edges)[i]->getDestination()->getInfo()) {
                returner = (*edges)[i];
            }
        }
        if (!returner) {
            throw "No road found...";
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
