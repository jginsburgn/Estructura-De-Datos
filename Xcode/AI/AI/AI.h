//
//  AI.h
//  AI
//
//  Created by Jonathan Ginsburg on 5/2/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#ifndef AI_AI_h
#define AI_AI_h

#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>

#include "Vertex.h"
#include "City.h"
#include "Road.h"
#include "Path.h"

template <class T>
class SearchNode {
    
private:
    
    T * state = nullptr;
    Path path;
    long double cost = 0;
    
public:
    
    SearchNode() {}
    SearchNode(T * newState) {
        setState(newState);
    }
    
    T * getState() const {
        return state;
    }
    
    Path getPath() const {
        return path;
    }
    
    long double getCost() const {
        return cost;
    }
    
    void setState(T * newState){
        state = newState;
    }
    
    void setPath(Path newPath) {
        path = newPath;
    }
    
    void setCost(long double newCost){
        cost = newCost;
    }
    
    void addStep(Edge<City, Road> * newStep){
        path.addStep(newStep);
    }
    
    bool operator == (const SearchNode<T> & searchNode) const {
        if (getPath().getSteps().size() != searchNode.getPath().getSteps().size() || getCost() != searchNode.getCost() || *getState()==*searchNode.getState()) {
            return false;
        }
        else{
            for (int i = 0; i < getPath().getSteps().size(); ++i) {
                if (*getPath().getSteps()[i] != *searchNode.getPath().getSteps()[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    
};

class AI {
    
    static bool isInVector(std::vector<Vertex<City, Road> *> vector, Vertex<City, Road> city){
        for (int i = 0; i < vector.size(); ++i) {
            if (*vector.at(i) == city) {
                return true;
            }
        }
        return false;
    }
    
//    static bool isInVector(std::vector<SearchNode<Vertex<City, Road>>> vector, SearchNode<Vertex<City, Road>> city){
//        for (int i = 0; i < vector.size(); ++i) {
//            if (vector.at(i) == city) {
//                return true;
//            }
//        }
//        return false;
//    }
    
    static bool isInQueue(std::queue<SearchNode<Vertex<City, Road>>> queue, Vertex<City, Road> city){
        while (!queue.empty()){
            Vertex<City, Road> cityToCompare = *queue.front().getState();
            queue.pop();
            if (city == cityToCompare) {
                return true;
            }
        }
        return false;
    }
    
    static bool isInStack(std::stack<SearchNode<Vertex<City, Road>>> stack, Vertex<City, Road> city){
        while (!stack.empty()){
            Vertex<City, Road> cityToCompare = *stack.top().getState();
            stack.pop();
            if (city == cityToCompare) {
                return true;
            }
        }
        return false;
    }
    
    static bool exploreBreadthFirstSearchNode(SearchNode<Vertex<City, Road>> & nodeToExplore, std::queue<SearchNode<Vertex<City, Road>>> & frontier, std::vector<Vertex<City, Road> *> & exploredVertices, Vertex<City, Road> & destination, bool verbose) {
        if (*nodeToExplore.getState() == destination) return true;
        else{
            std::vector<Edge<City, Road> *> outgoingEdges = (*(*nodeToExplore.getState()).getOutgoingEdges());
            for (int i = 0; i < outgoingEdges.size(); ++i) {
                Edge<City, Road> * currentEdge = outgoingEdges[i];
                if (verbose) std::cout << "Discovering road to " << currentEdge->getDestination()->getInfo()->getName() << std::endl;
                Vertex<City, Road> * newState = currentEdge->getDestination();
                SearchNode<Vertex<City, Road>> newSearchNode(newState);
                newSearchNode.setPath(nodeToExplore.getPath());
                newSearchNode.addStep(currentEdge);
                newSearchNode.setCost(nodeToExplore.getCost() + currentEdge->getInfo()->getLength());
                if (!(isInVector(exploredVertices, *newState) || isInQueue(frontier, *newState) || *newState == *nodeToExplore.getState())) {
                    frontier.push(newSearchNode);
                }
            }
        }
        return false;
    }
    
    static bool exploreDepthFirstSearchNode(SearchNode<Vertex<City, Road>> & nodeToExplore, std::stack<SearchNode<Vertex<City, Road>>> & frontier, std::vector<Vertex<City, Road> *> & exploredVertices, Vertex<City, Road> & destination, bool verbose) {
        if (*nodeToExplore.getState() == destination) return true;
        else{
            std::vector<Edge<City, Road> *> outgoingEdges = (*(*nodeToExplore.getState()).getOutgoingEdges());
            for (int i = 0; i < outgoingEdges.size(); ++i) {
                Edge<City, Road> * currentEdge = outgoingEdges[i];
                if (verbose) std::cout << "Discovering road to " << currentEdge->getDestination()->getInfo()->getName() << std::endl;
                Vertex<City, Road> * newState = currentEdge->getDestination();
                SearchNode<Vertex<City, Road>> newSearchNode(newState);
                newSearchNode.setPath(nodeToExplore.getPath());
                newSearchNode.addStep(currentEdge);
                newSearchNode.setCost(nodeToExplore.getCost() + currentEdge->getInfo()->getLength());
                if (!(isInVector(exploredVertices, *newState) || isInStack(frontier, *newState) || *newState == *nodeToExplore.getState())) {
                    frontier.push(newSearchNode);
                }
            }
        }
        return false;
    }
    
public:
    
    static void breadthFirstSearch(Vertex<City, Road> * origin, Vertex<City, Road> * destination, bool verbose){
        SearchNode<Vertex<City, Road>> originNode(origin);
        std::vector<Vertex<City, Road> *> exploredVertices;
        std::queue<SearchNode<Vertex<City, Road>>> frontier;
        frontier.push(originNode);
        while (!frontier.empty()) {
            SearchNode<Vertex<City, Road>> nodeToExplore = frontier.front();
            if (verbose) std::cout << "Discovering city " << *nodeToExplore.getState()->getInfo() << std::endl;
            exploredVertices.push_back(nodeToExplore.getState());
            frontier.pop();
            if (exploreBreadthFirstSearchNode(nodeToExplore, frontier, exploredVertices, *destination, verbose)){
                std::cout << "The following route was found with " << nodeToExplore.getCost() << " of cost:\n" << nodeToExplore.getPath();
                return;
            }
        }
        std::cout << "No solution found..." << std::endl;
    }
    
    static void depthFirstSearch(Vertex<City, Road> * origin, Vertex<City, Road> * destination, bool verbose){
        
        SearchNode<Vertex<City, Road>> originNode(origin);
        std::vector<SearchNode<Vertex<City, Road>>> solutions;
        std::vector<Vertex<City, Road> *> exploredVertices;
        std::stack<SearchNode<Vertex<City, Road>>> frontier;
        frontier.push(originNode);
        while (!frontier.empty()) {
            SearchNode<Vertex<City, Road>> nodeToExplore = frontier.top();
            if (verbose) std::cout << "Discovering " << *nodeToExplore.getState()->getInfo() << std::endl;
            exploredVertices.push_back(nodeToExplore.getState());
            frontier.pop();
            if (exploreDepthFirstSearchNode(nodeToExplore, frontier, exploredVertices, *destination, verbose)) solutions.push_back(nodeToExplore);
        }
        if (solutions.empty()) {
            std::cout << "No solution found..." << std::endl;
        }
        else{
            int cheapest = 0;
            for (int i = 0; i < solutions.size(); ++i) {
                if (solutions[i].getCost() < solutions[cheapest].getCost()) {
                    cheapest = i;
                }
            }
            std::cout << "The following route was found with " << solutions[cheapest].getCost() << " of cost:\n" << solutions[cheapest].getPath();
        }
        
    }
    
};

#endif
