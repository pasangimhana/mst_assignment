#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "../helpers/edge.h"

class Graph {
public:
    virtual void addEdge(int u, int v, int weight) = 0;
    virtual void printGraph() = 0;
    virtual int getVertices() const = 0;
    virtual int getWeight(int u, int v) const = 0;
    virtual std::vector<Edge> getEdges() const = 0;
    virtual void kruksklMST() const = 0;
    virtual void primMSTLazy(int source) const = 0;
    virtual void primMSTEager(int source) const = 0;
};

#endif // GRAPH_H
