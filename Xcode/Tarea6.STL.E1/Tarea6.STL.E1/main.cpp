//
//  main.cpp
//  Tarea6.STL.E1
//
//  Created by Jonathan Ginsburg on 4/28/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Graph.h"

int main(int argc, const char * argv[]) {
    Graph<std::string, int> graph;
    try {
        graph.addVertex("Jonathan");
        graph.addVertex("Samuel");
        graph.addEdge(10, "Jonathan", "Samuel");
        graph.addEdge(20, "Jonathan", "Samuel");
        graph.removeVertex("Jonathan");
    } catch (const char * exception) {
        std::cout << exception << std::endl;
    }
    std::cout << graph;
    return 0;
}
