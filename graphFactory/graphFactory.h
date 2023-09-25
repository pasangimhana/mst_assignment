// GraphFactory.h

#pragma once
#include "graph.h"

class GraphFactory {
public:
    virtual Graph* createGraph(int vertices, double density) = 0;
};
