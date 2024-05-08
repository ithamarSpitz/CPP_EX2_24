Algorithms.hpp and Algorithms.cpp:


bool Algorithms::isConnected(const Graph& g)
Algorithm: Depth First Search (DFS)
Description: Checks if the graph is connected by performing a DFS traversal from a starting vertex and checking if all vertices are visited.

std::string Algorithms::shortestPath(const Graph& g, int start, int end)
Algorithm: Dijkstra's Algorithm
Description: Finds the shortest path from a starting vertex to an ending vertex using Dijkstra's algorithm.

bool Algorithms::isContainsCycle(const Graph& g)
Algorithm: Depth First Search (DFS) with cycle detection
Description: Checks if the graph contains any cycles by performing a DFS traversal and keeping track of vertices in the recursion stack.

std::string Algorithms::isBipartite(const Graph& g)
Algorithm: Bipartite Graph Check
Description: Checks if the graph is bipartite by assigning colors to vertices and ensuring adjacent vertices have different colors.

bool Algorithms::negativeCycle(const Graph& g)
Algorithm: Bellman-Ford Algorithm
Description: Detects if the graph contains a negative cycle using the Bellman-Ford algorithm.


Graph.hpp and Graph.cpp:


void Graph::loadGraph(const std::vector<std::vector<int>>& graph)
Description: Loads a graph represented by its adjacency matrix into the Graph object.

void Graph::printGraph() const
Description: Prints the adjacency matrix of the graph.

const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const
Description: Returns the adjacency matrix of the graph.

Please note that the provided code snippets contain comments with URLs to the original sources of the algorithms for further reference.