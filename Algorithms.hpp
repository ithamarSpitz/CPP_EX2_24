//5249
//itamar.shpitzer@msmail.ariel.ac.il

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <string>

namespace ariel {

    class Algorithms {
    public:
        // Check if the graph is connected
        static bool isConnected(const Graph& g);

        // Find shortest path between two vertices
        static std::string shortestPath(const Graph& g, int start, int end);

        // Check if the graph contains a cycle
        static bool isContainsCycle(const Graph& g);

        // Check if the graph is bipartite
        static std::string isBipartite(const Graph& g);

        // Find a negative cycle in the graph
        static bool negativeCycle(const Graph& g);
    };

}

#endif // ALGORITHMS_HPP
