#ifndef ADJLISTGRAPH_H
#define ADJLISTGRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <climits>

#include "graph.h"
#include "../helpers/disjoint.h"
#include "../helpers/edge.h"

class AdjListGraph : public Graph {
private:
    int V;
    std::vector<std::vector<std::pair<int, int>>> adjList;

public:
    explicit AdjListGraph(int vertices);
    void addEdge(int u, int v, int weight) override;
    void printGraph() override;
    int getVertices() const override;
    int getWeight(int u, int v) const override;
    std::vector<Edge> getEdges() const override;


    // Algorithms
    void kruksklMST() const override;
    void primMSTLazy(int source) const override;
    void primMSTEager(int source) const override;
};

#endif // ADJLISTGRAPH_H
