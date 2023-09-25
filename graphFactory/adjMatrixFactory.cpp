//
// Created by phaser on 24/09/23.
//
#include "adjMatrixFactory.h"

Graph* AdjMatrixGraphFactory::createGraph(int vertices, double density) {
    int maxEdges = (vertices * (vertices - 1)) / 2;
    if (density > 1) {
        std::cout << "Density cannot be greater than 1. Setting density to 1.\n";
        density = 1;
    } else if (density < 0) {
        std::cout << "Density cannot be less than 0. Setting density to 0.\n";
        density = 0;
    }
    int numEdges = static_cast<int>(maxEdges * density);

    auto* graph = new AdjMatrixGraph(vertices);

    // Add random edges based on density
    for (int i = 0; i < numEdges; ++i) {
        int u = rand() % vertices;
        int v = rand() % vertices;
        int weight = rand() % 100 + 1; // Assuming weights are between 1 and 10
        graph->addEdge(u, v, weight);
    }

    return graph;
}

