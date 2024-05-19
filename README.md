# Graph Algorithms Library

This library provides implementations of various graph algorithms in C++. Below is a brief description of each function in the library and its corresponding algorithm.

## Algorithms.hpp and Algorithms.cpp

### isConnected

**Algorithm:** Depth First Search (DFS)  
**Description:** Checks if the graph is connected by performing a DFS traversal from a starting vertex and checking if all vertices are visited.  
[Further reference](https://en.wikipedia.org/wiki/Depth-first_search)

### shortestPath

**Algorithm:** Dijkstra's Algorithm  
**Description:** Finds the shortest path from a starting vertex to an ending vertex using Dijkstra's algorithm.  
[Further reference](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)

### isContainsCycle

**Algorithm:** Depth First Search (DFS) with cycle detection  
**Description:** Checks if the graph contains any cycles by performing a DFS traversal and keeping track of vertices in the recursion stack.  
[Further reference](https://en.wikipedia.org/wiki/Cycle_detection#Depth-First_Search)

### isBipartite

**Algorithm:** Bipartite Graph Check  
**Description:** Checks if the graph is bipartite by assigning colors to vertices and ensuring adjacent vertices have different colors.  
[Further reference](https://en.wikipedia.org/wiki/Bipartite_graph)

### negativeCycle

**Algorithm:** Bellman-Ford Algorithm  
**Description:** Detects if the graph contains a negative cycle using the Bellman-Ford algorithm.  
[Further reference](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)

## Graph.hpp and Graph.cpp

### loadGraph

**Description:** Loads a graph represented by its adjacency matrix into the Graph object.

### printGraph

**Description:** Prints the adjacency matrix of the graph.

### getAdjacencyMatrix

**Description:** Returns the adjacency matrix of the graph.

## Explanation of Functions in Graph.cpp

- **Graph::Graph:** Constructor for the Graph class.
- **Graph::~Graph:** Destructor for the Graph class.
- **Graph::loadGraph:** Loads a graph represented by its adjacency matrix into the Graph object. It checks if the matrix is square, and if not, it throws an invalid argument exception.
- **Graph::printGraph:** Prints the adjacency matrix of the graph as a string.
- **Graph::getAdjacencyMatrix:** Returns a constant reference to the adjacency matrix of the graph.
- **Graph::operator+:** Performs matrix addition between two graphs. It checks if the matrices have the same dimensions, and if not, it throws an invalid argument exception.
- **Graph::operator-:** Performs matrix subtraction between two graphs. It utilizes the addition operator and negation.
- **Graph::operator*:** Performs scalar multiplication with the graph's adjacency matrix or matrix multiplication between two graphs. It checks if the matrices have the same dimensions for matrix multiplication.
- **Graph::operator++:** Increases all edge weights in the graph by 1.
- **Graph::operator--:** Decreases all edge weights in the graph by 1.
- **Graph::operator+=:** Performs addition assignment between two graphs.
- **Graph::operator-=:** Performs subtraction assignment between two graphs.
- **Graph::operator==, operator>, operator>=, operator<, operator<=, operator!=:** Implements comparison operators for graphs based on their adjacency matrices.
- **Graph::operator+(const int scalar), operator-(const int scalar), operator++(), operator--():** Implements unary and binary operators for scalar operations and increment/decrement operations.
- **operator+(const int scalar, const Graph& matrix), operator-(const int scalar, const Graph& matrix):** Performs addition and subtraction between a scalar and a graph, respectively.
- **Graph::operator+, operator-:** Implements unary plus and minus operators for graphs.
- **Graph::operator<<:** Overrides the << operator to print the adjacency matrix of a graph.
