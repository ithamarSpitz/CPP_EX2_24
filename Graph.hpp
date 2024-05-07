#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <string>

namespace ariel {

    class Graph {
    private:
        std::vector<std::vector<int>> adjacencyMatrix;

    public:
        // Constructor
        Graph();

        // Destructor
        ~Graph();

        // Load graph from adjacency matrix
        void loadGraph(const std::vector<std::vector<int>>& graph);

        // Print the graph (for debugging purposes)
        void printGraph() const;

        // Get the adjacency matrix
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
    };

} // namespace ariel

#endif // GRAPH_HPP
