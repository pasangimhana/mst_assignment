#include "adjMatrix.h"
#include "adjList.h"

AdjMatrixGraph::AdjMatrixGraph(int vertices) : V(vertices) {
    adjMatrix.resize(V, std::vector<int>(V, 0));
}

void AdjMatrixGraph::addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;
}

//  Adjecency Matrix Graph Print Function
void AdjMatrixGraph::printGraph() {
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cout << adjMatrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int AdjMatrixGraph::getVertices() const {
    return V;
}

int AdjMatrixGraph::getWeight(int u, int v) const {
    return adjMatrix[u][v];
}

void AdjMatrixGraph::kruksklMST() const {
    std::vector<Edge> edges = getEdges();
    std::sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    });

    int V = getVertices();
    DisjointSet ds(V);

    std::vector<Edge> result;

    for (const Edge &edge: edges) {
        int u = edge.source;
        int v = edge.destination;

        int pu = ds.find(u);
        int pv = ds.find(v);

        if (pu != pv) {
            result.push_back(edge);
            ds.merge(pu, pv);
        }
    }

    // Output the minimum spanning tree
//    std::cout << "Minimum Spanning Tree (MST) using Kruskal's Algorithm:\n";
//    for (const Edge &edge: result) {
//        std::cout << edge.source << " - " << edge.destination << " (Weight: " << edge.weight << ")\n";
//    }
}

void AdjMatrixGraph::primMSTLazy(int source) const {
    std::vector<bool> inMST(V, false);
    std::vector<Edge> edgeTo(V);
    std::vector<int> distTo(V, INT_MAX);

    distTo[source] = 0;
    edgeTo[source] = {source, source, 0};

    for (int i = 0; i < V; ++i) {
        int u = -1;
        for (int j = 0; j < V; ++j) {
            if (!inMST[j] && (u == -1 || distTo[j] < distTo[u]))
                u = j;
        }

        inMST[u] = true;

        for (int v = 0; v < V; ++v) {
            int weight = getWeight(u, v);
            if (!inMST[v] && weight != 0 && weight < distTo[v]) {
                distTo[v] = weight;
                edgeTo[v] = {u, v, weight};
            }
        }
    }

//    std::cout << "Minimum Spanning Tree (MST) using Lazy Prim's Algorithm:\n";
//    for (int i = 0; i < V; ++i) {
//        if (i != source) {
//            std::cout << edgeTo[i].source << " - " << edgeTo[i].destination << " (Weight: " << edgeTo[i].weight
//                      << ")\n";
//        }
}

void AdjMatrixGraph::primMSTEager(int source) const {
    std::vector<Edge> edgeTo(V);
    std::vector<int> distTo(V, INT_MAX);
    std::vector<bool> inHeap(V, true);

    distTo[source] = 0;
    edgeTo[source] = {source, source, 0};

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inHeap[u] = false;

        for (int v = 0; v < V; ++v) {
            int weight = getWeight(u, v);
            if (inHeap[v] && weight != 0 && weight < distTo[v]) {
                distTo[v] = weight;
                edgeTo[v] = {u, v, weight};
                pq.push({distTo[v], v});
            }
        }
    }

//    std::cout << "Minimum Spanning Tree (MST) using Eager Prim's Algorithm:\n";
//    for (int i = 0; i < V; ++i) {
//        if (i != source) {
//            std::cout << edgeTo[i].source << " - " << edgeTo[i].destination << " (Weight: " << edgeTo[i].weight
//                      << ")\n";
//        }
//    }
}

std::vector<Edge> AdjMatrixGraph::getEdges() const {
    std::vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) {
            int weight = getWeight(i, j);
            if (weight != 0) {
                edges.push_back({i, j, weight});
            }
        }
    }
    return edges;
}
