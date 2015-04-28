//
//  main.cpp
//  Tarea6.STL.E1
//
//  Created by Jonathan Ginsburg on 4/28/15.
//  Copyright (c) 2015 Jonathan Ginsburg. All rights reserved.
//

#include "Graph.h"

int main(int argc, const char * argv[]) {
    Graph<std::string, int> graphA;
    try {
        graphA.addVertex("Jonathan");
        graphA.addVertex("Samuel");
        graphA.addEdge(10, "Jonathan", "Samuel");
        graphA.addEdge(20, "Jonathan", "Samuel");
    } catch (const char * exception) {
        std::cout << exception << std::endl;
    }
    Graph<std::string, int> graphB = graphA;
    graphB.removeVertex("Samuel");
    std::cout << graphA;
    std::cout << std::endl;
    std::cout << graphB;
    return 0;
}
