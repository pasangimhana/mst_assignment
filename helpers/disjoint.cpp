#include "disjoint.h"

DisjointSet::DisjointSet(int n) {
    parent.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int DisjointSet::find(int u) {
    if (u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void DisjointSet::merge(int u, int v) {

    int pu = find(u);
    int pv = find(v);

    if (pu == pv)
        return;

    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pu] > rank[pv]) {
        parent[pv] = pu;
    } else {
        parent[pu] = pv;
        rank[pv]++;
    }
}
