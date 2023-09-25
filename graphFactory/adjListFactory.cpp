//
// Created by phaser on 24/09/23.
//
#include "adjListFactory.h"


Graph* AdjListGraphFactory::createGraph(int vertices, double density) {
    int maxEdges = (vertices * (vertices - 1)) / 2;
    int numEdges = maxEdges * density;

    auto* graph = new AdjListGraph(vertices);

    // Add random edges based on density
    for (int i = 0; i < numEdges; ++i) {
        int u = rand() % vertices;
        int v = rand() % vertices;
        int weight = rand() % 10 + 1; // Assuming weights are between 1 and 10
        graph->addEdge(u, v, weight);
    }

    return graph;
}

