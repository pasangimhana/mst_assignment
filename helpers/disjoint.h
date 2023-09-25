#pragma once

#ifndef MST_ASSIGNMENT_DISJOINT_H
#define MST_ASSIGNMENT_DISJOINT_H

#include <vector>

class DisjointSet {
private:
    std::vector<int> parent, rank;

public:
    explicit DisjointSet(int n);
    int find(int u);
    void merge(int u, int v);
};


#endif //MST_ASSIGNMENT_DISJOINT_H
