cmake_minimum_required(VERSION 3.0)
project(MST)

# Source files
set(SOURCE_FILES
        graphFactory/adjList.cpp
        graphFactory/adjList.h
        helpers/disjoint.cpp
        helpers/disjoint.h
        helpers/edge.h
        graphFactory/graph.h
        main.cpp
        graphFactory/adjMatrix.h
        graphFactory/adjMatrix.cpp
        graphFactory/adjMatrixFactory.h
        graphFactory/adjListFactory.h
        graphFactory/graphFactory.h
        graphFactory/adjMatrixFactory.cpp
        graphFactory/adjListFactory.cpp
)

# Executable target
add_executable(MST ${SOURCE_FILES})
