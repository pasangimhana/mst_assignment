// AdjMatrixGraphFactory.h

#pragma once
#include "graphFactory.h"
#include "adjMatrix.h"

class AdjMatrixGraphFactory : public GraphFactory {
public:
    Graph* createGraph(int vertices, double density) override;
};
