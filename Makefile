CC = g++
CFLAGS = -Wall -std=c++11

# Source files
SOURCE_FILES = \
    graphFactory/adjList.cpp \
    graphFactory/adjList.h \
    helpers/disjoint.cpp \
    helpers/disjoint.h \
    helpers/edge.h \
    graphFactory/graph.h \
    main.cpp \
    graphFactory/adjMatrix.h \
    graphFactory/adjMatrix.cpp \
    graphFactory/adjMatrixFactory.h \
    graphFactory/adjListFactory.h \
    graphFactory/graphFactory.h \
    graphFactory/adjMatrixFactory.cpp \
    graphFactory/adjListFactory.cpp

# Executable target
EXECUTABLE = MST

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCE_FILES)
	$(CC) $(CFLAGS) $(SOURCE_FILES) -o $(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
