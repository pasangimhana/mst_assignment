#include "adjList.h"
#include "adjMatrix.h"

AdjListGraph::AdjListGraph(int vertices) : V(vertices) {
    adjList.resize(V);
}

void AdjListGraph::addEdge(int u, int v, int weight) {
    adjList[u].emplace_back(v, weight);
    adjList[v].emplace_back(u, weight);
}

void AdjListGraph::printGraph() {
    for (int i = 0; i < V; ++i) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for (const auto &pair: adjList[i]) {
            std::cout << pair.first << " (Weight: " << pair.second << ") ";
        }
        std::cout << std::endl;
    }
}

int AdjListGraph::getVertices() const {
    return V;
}

int AdjListGraph::getWeight(int u, int v) const {
    for (const auto &pair: adjList[u]) {
        if (pair.first == v) {
            return pair.second;
        }
    }
    return 0; // Assuming 0 represents no edge
}

void AdjListGraph::kruksklMST() const {
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
//    for (const Edge& edge : result) {
//        std::cout << edge.source << " - " << edge.destination << " (Weight: " << edge.weight << ")\n";
//    }
}

void AdjListGraph::primMSTLazy(int source) const {
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

        for (const auto &pair: adjList[u]) {
            int v = pair.first;
            int weight = pair.second;
            if (!inMST[v] && weight < distTo[v]) {
                distTo[v] = weight;
                edgeTo[v] = {u, v, weight};
            }
        }
    }

//    std::cout << "Minimum Spanning Tree (MST) using Lazy Prim's Algorithm:\n";
//    for (int i = 0; i < V; ++i) {
//        if (i != source) {
//            std::cout << edgeTo[i].source << " - " << edgeTo[i].destination << " (Weight: " << edgeTo[i].weight << ")\n";
//        }
//    }
}

void AdjListGraph::primMSTEager(int source) const {

    int max = INT_MAX;
    std::vector<Edge> edgeTo(V);
    std::vector<int> distTo(V, INT_MAX);
    std::vector<bool> inHeap(V, true);

    distTo[source] = 0;
    edgeTo[source] = {source, source, 0};

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.emplace(0, source);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inHeap[u] = false;

        for (const auto &pair: adjList[u]) {
            int v = pair.first;
            int weight = pair.second;
            if (inHeap[v] && weight < distTo[v]) {
                distTo[v] = weight;
                edgeTo[v] = {u, v, weight};
                pq.emplace(distTo[v], v);
            }
        }
    }

//    std::cout << "Minimum Spanning Tree (MST) using Eager Prim's Algorithm:\n";
//    for (int i = 0; i < V; ++i) {
//        if (i != source) {
//            std::cout << edgeTo[i].source << " - " << edgeTo[i].destination << " (Weight: " << edgeTo[i].weight << ")\n";
//        }
}


std::vector<Edge> AdjListGraph::getEdges() const {
    std::vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (const auto &pair: adjList[i]) {
            Edge edge{};
            edge.source = i;
            edge.destination = pair.first;
            edge.weight = pair.second;
            edges.push_back(edge);
        }
    }
    return edges;
}

