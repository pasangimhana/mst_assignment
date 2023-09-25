//
// Created by phaser on 24/09/23.
//

#ifndef MST_ADJLISTFACTORY_H
#define MST_ADJLISTFACTORY_H

// AdjListGraphFactory.h

#pragma once
#include "graphFactory.h"
#include "adjList.h"

class AdjListGraphFactory : public GraphFactory {
public:
    Graph* createGraph(int vertices, double density) override;
};


#endif //MST_ADJLISTFACTORY_H
