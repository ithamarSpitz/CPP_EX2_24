# Graph Algorithms Library

This library provides implementations of various graph algorithms in C++. Below is a brief description of each algorithm and its corresponding function in the library.

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

