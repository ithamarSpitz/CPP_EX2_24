//5249
//itamar.shpitzer@msmail.ariel.ac.il

#include "Graph.hpp"
#include <iostream>
using namespace std;

namespace ariel {

    Graph::Graph() {}

    Graph::~Graph() {}

    void Graph::loadGraph(const std::vector<std::vector<int>>& graph) {
        int rows = graph.size();
        for (const auto& row : graph) {
            if (rows != row.size()) {
                throw std::invalid_argument("Graph is not square");
            }
        }
        adjacencyMatrix = graph;
    }

    void Graph::printGraph() const {
        for (const auto& row : adjacencyMatrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

}
