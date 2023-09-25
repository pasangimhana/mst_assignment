#include "graphFactory/graphFactory.h"
#include "graphFactory/adjMatrixFactory.h"
#include "graphFactory/adjListFactory.h"

#include <iostream>
#include <chrono>

template<typename Func>
double measureTime(Func func) {
    auto start = std::chrono::high_resolution_clock::now(); // Record start time

    func(); // Call the function to be measured

    auto end = std::chrono::high_resolution_clock::now(); // Record end time
    std::chrono::duration<double> duration = end - start; // Calculate duration

    return duration.count(); // Return time taken in seconds
}


int main() {

// Matrix Graph Factory
    GraphFactory *graphFactory = new AdjMatrixGraphFactory();

    // Create a graph with 10 vertices and 10% density
    Graph *sparseGraph = graphFactory->createGraph(10000, 0.1);

    // Create a graph with 10 vertices and 90% density
    Graph *denseGraph = graphFactory->createGraph(10000, 0.9);


    std::cout << "---------------Adjacency Matrix Graph---------------\n" << std::endl;
    // Number of vertices and edges
    std::cout << "Sparse Graph: " << sparseGraph->getVertices() << " vertices, " << sparseGraph->getEdges().size()
              << " edges\n";
    std::cout << "Dense Graph: " << denseGraph->getVertices() << " vertices, " << denseGraph->getEdges().size()
              << " edges\n\n";


    // Check time taken for MST algorithms
    // Krukskal
    std::cout << "Krukskal's Algorithm\n";
    std::cout << "Sparse Graph: " << measureTime([&sparseGraph]() { sparseGraph->kruksklMST(); }) << " seconds\n";
    std::cout << "Dense Graph: " << measureTime([&denseGraph]() { denseGraph->kruksklMST(); }) << " seconds\n\n";

    // Prim's Lazy
    std::cout << "Prim's Lazy Algorithm\n";
    std::cout << "Sparse Graph: " << measureTime([&sparseGraph]() { sparseGraph->primMSTLazy(0); }) << " seconds\n";
    std::cout << "Dense Graph: " << measureTime([&denseGraph]() { denseGraph->primMSTLazy(0); }) << " seconds\n\n";

    // Prim's Eager
    std::cout << "Prim's Eager Algorithm\n";
    std::cout << "Sparse Graph: " << measureTime([&sparseGraph]() { sparseGraph->primMSTEager(0); }) << " seconds\n";
    std::cout << "Dense Graph: " << measureTime([&denseGraph]() { denseGraph->primMSTEager(0); }) << " seconds\n\n";

    // Delete the graphs
    delete sparseGraph;
    delete denseGraph;
    delete graphFactory;


    // Create List Graphs and the same thing

    GraphFactory *listFactory = new AdjListGraphFactory();

    // Create a graph with 10 vertices and 10% density
    Graph *sparseListGraph = listFactory->createGraph(10000, 0.1);

    // Create a graph with 10 vertices and 90% density
    Graph *denseListGraph = listFactory->createGraph(10000, 0.9);


    std::cout << "---------------Adjacency List Graph---------------\n" << std::endl;

    // Number of vertices and edges
    std::cout << "Sparse Graph: " << sparseListGraph->getVertices() << " vertices, "
              << sparseListGraph->getEdges().size() << " edges\n";
    std::cout << "Dense Graph: " << denseListGraph->getVertices() << " vertices, " << denseListGraph->getEdges().size()
              << " edges\n\n";

    // Check time taken for MST algorithms
    // Krukskal
    std::cout << "Krukskal's Algorithm\n";
    std::cout << "Sparse Graph: " << measureTime([&sparseListGraph]() { sparseListGraph->kruksklMST(); })
              << " seconds\n";
    std::cout << "Dense Graph: " << measureTime([&denseListGraph]() { denseListGraph->kruksklMST(); })
              << " seconds\n\n";

    // Prim's Lazy
    std::cout << "Prim's Lazy Algorithm\n";
    std::cout << "Sparse Graph: " << measureTime([&sparseListGraph]() { sparseListGraph->primMSTLazy(0); })
              << " seconds\n";
    std::cout << "Dense Graph: " << measureTime([&denseListGraph]() { denseListGraph->primMSTLazy(0); })
              << " seconds\n\n";

    // Prim's Eager
    std::cout << "Prim's Eager Algorithm\n";
    std::cout << "Sparse Graph: " << measureTime([&sparseListGraph]() { sparseListGraph->primMSTEager(0); })
              << " seconds\n";
    std::cout << "Dense Graph: " << measureTime([&denseListGraph]() { denseListGraph->primMSTEager(0); })
              << " seconds\n\n";

    // Delete the graphs
    delete sparseListGraph;
    delete denseListGraph;
    delete listFactory;

    return 0;
}
