//
//  main.cpp
//  EF.E1.Grafos
//
//  Created by Jonathan Ginsburg on 5/12/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include <iostream>
#include "Graph.h"
#include "Helper.h"

void connectAll(Graph<char, int> graph) {
    
}

int main(int argc, const char * argv[]) {
    Graph<int, int> graph;
    for (int i = 1; i <= 3; ++i) {
        graph.addVertex(i);
    }
    std::string connected = graph.isMesh() ? "yes" : "no";
    std::cout << graph << std::endl;
    std::cout << "Graph is mesh: " << connected << std::endl;
    graph.connectAll();
    connected = graph.isMesh() ? "yes" : "no";
    std::cout << graph << std::endl;
    std::cout << "Graph is mesh: " << connected << std::endl;
    return 0;
}
