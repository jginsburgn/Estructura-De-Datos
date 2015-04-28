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
    
    void copy(const Graph<V, E> & source){
        for (int i = 0; i < source.getVertices()->size(); ++i) {
            addVertex(*(source.getVertexAt(i)->getInfo()));
        }
        for (int i = 0; i < source.getEdges()->size(); ++i) {
            Edge<V, E> * sourceEdge = source.getEdgeAt(i);
            addEdge(*sourceEdge->getInfo(), *sourceEdge->getOrigin()->getInfo(), *sourceEdge->getDestination()->getInfo());
        }
    }
    
public:
    
    Graph() {};
    
    Graph(const Graph<V, E> & source) {
        copy(source);
    }
    
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
    
    std::vector<Vertex<V, E> *> * getVertices() const{
        return vertices;
    }
    
    std::vector<Edge<V, E> *> * getEdges() const{
        return edges;
    }
    
    Vertex<V, E> * getVertex(V info) const{
        Vertex<V, E> compare(info);
        for (int i = 0; i < vertices->size(); ++i) {
            if (compare == *getVertexAt(i)) {
                return getVertexAt(i);
            }
        }
        throw "Vertex does not exist...";
    }
    
    Edge<V, E> * getEdge(E info, V origin, V destination) const{
        Edge<V, E> compare(info, getVertex(origin), getVertex(destination));
        for (int i = 0; i < edges->size(); ++i) {
            if (compare == *getEdgeAt(i)) {
                return getEdgeAt(i);
            }
        }
        throw "Edge does not exist...";
    }
    
    Vertex<V, E> * getVertexAt(int i) const{
        return (*vertices)[i];
    }
    
    Edge<V, E> * getEdgeAt(int i) const{
        return (*edges)[i];
    }
    
    bool vertexExists(V info) const {
        Vertex<V, E> compare(info);
        for (int i = 0; i < vertices->size(); ++i) {
            if (compare == *getVertexAt(i)) {
                return true;
            }
        }
        return false;
    }
    
    bool edgeExists(E info, V origin, V destination) const {
        try {
            Edge<V, E> compare(info, getVertex(origin), getVertex(destination));
            for (int i = 0; i < edges->size(); ++i) {
                if (compare == *getEdgeAt(i)) {
                    return true;
                }
            }
            return false;
        } catch (const char * exception) {
            throw exception;
        }
    }
    
    void addVertex(V info){
        if (vertexExists(info)) throw "Vertex already exists...";
        Vertex<V, E> * newVertex = new Vertex<V, E>(info);
        vertices->push_back(newVertex);
    }
    
    void addEdge(E info, V origin, V destination){
        
        if (edgeExists(info, origin, destination)) throw "Edge already exists...";
        
        try {
            Vertex<V, E> * originVertex = getVertex(origin);
            Vertex<V, E> * destinationVertex = getVertex(destination);
            Edge<V, E> * newEdge = new Edge<V, E>(info, originVertex, destinationVertex);
            originVertex->connectOutgoingEdge(newEdge);
            destinationVertex->connectIncomingEdge(newEdge);
            edges->push_back(newEdge);
        } catch (const char * exception) {
            throw exception;
        }
    }
    
    void removeVertex(V info){
        try {
            removeVertex(getVertex(info));
        } catch (const char * exception) {
            throw exception;
        }
    }
    
    void removeVertex(Vertex<V, E> * vertexToDelete){
        if (vertexToDelete) {
            int position = -1;
            for (int i = 0; i < vertices->size(); ++i) {
                if (vertexToDelete == getVertexAt(i)) {
                    position = i;
                    break;
                }
            }
            if (position == -1) {
                throw "Vertex not in graph...";
            }
            while (0 != vertexToDelete->getEdges()->size()) {
                Edge<V, E> * edgeToDelete = (*vertexToDelete->getEdges())[0];
                removeEdge(edgeToDelete);
            }
            vertices->erase(vertices->begin() + position);
            delete vertexToDelete;
        }
        else throw "No vertex to remove...(null)";
    }
    
    void removeEdge(E info, V origin, V destination){
        try {
            removeEdge(getEdge(info, origin, destination));
        } catch (const char * exception) {
            throw exception;
        }
    }
    
    void removeEdge(Edge<V, E> * edgeToDelete){
        if (edgeToDelete) {
            int position = -1;
            for (int i = 0; i < edges->size(); ++i) {
                if (*getEdgeAt(i) == *edgeToDelete) {
                    position = i;
                    break;
                }
            }
            if (position == -1) {
                throw "Edge not in graph...";
            }
            if (edgeToDelete->getOrigin()) {
                edgeToDelete->getOrigin()->disconnectEdge(edgeToDelete);
            }
            if (edgeToDelete->getDestination()) {
                edgeToDelete->getDestination()->disconnectEdge(edgeToDelete);
            }
            edges->erase(edges->begin() + position);
            delete edgeToDelete;
        }
        else throw "No edge to remove...(null)";
    }
    
    void clear(){
        while (0 != vertices->size()) {
            removeVertex(getVertexAt(0));
        }
    }
    
    void disconnectAll() {
        while (edges->size() != 0) {
            removeEdge(getEdgeAt(0));
        }
    }
    
    Graph<V, E> & operator = (const Graph<V, E> & source){
        copy(source);
        return *this;
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
