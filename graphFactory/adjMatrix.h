
#ifndef MST_ADJMATRIX_H
#define MST_ADJMATRIX_H

#endif //MST_ADJMATRIX_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <climits>

#include "graph.h"
#include "../helpers/disjoint.h"
#include "../helpers/edge.h"

class AdjMatrixGraph : public Graph {
private:
    int V;
    std::vector<std::vector<int>> adjMatrix;

public:
    explicit AdjMatrixGraph(int vertices);
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

