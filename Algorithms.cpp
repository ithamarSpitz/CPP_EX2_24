// algorithms.cpp

#include "Algorithms.hpp"
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <iostream>
#include <sstream>

namespace ariel {

    namespace {


        // https://www.geeksforgeeks.org/detect-cycle-in-a-graph/

        void dfs(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, int v) {
            visited[static_cast<size_t>(v)] = true;
            for (size_t u = 0; u < graph.size(); ++u) {
                if (graph[static_cast<size_t>(v)][static_cast<size_t>(u)] && !visited[static_cast<size_t>(u)]) {
                    dfs(graph, visited, u);
                }
            }
        }


        // https://www.geeksforgeeks.org/detect-cycle-in-a-graph/


        bool hasCycle(const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<bool>& recStack, int v) {
            if (!visited[static_cast<size_t>(v)]) {
                visited[static_cast<size_t>(v)] = true;
                recStack[static_cast<size_t>(v)] = true;

                for (size_t u = 0; u < graph.size(); ++u) {
                    if (graph[static_cast<size_t>(v)][static_cast<size_t>(u)]) {
                        if (!visited[static_cast<size_t>(u)] && hasCycle(graph, visited, recStack, u)) {
                            return true;
                        } else if (recStack[static_cast<size_t>(u)]) {
                            return true;
                        }
                    }
                }
            }
            recStack[static_cast<size_t>(v)] = false;
            return false;
        }

        // https://algs4.cs.princeton.edu/44sp/index.php

        bool relaxEdges(const std::vector<std::vector<int>>& graph, std::vector<int>& dist, std::vector<int>& prev) {
            size_t n = graph.size();
            bool relaxed = false;

            for (size_t u = 0; u < n; ++u) {
                for (size_t v = 0; v < n; ++v) {
                    if (graph[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                        prev[v] = u;
                        relaxed = true;
                    }
                }
            }

            return relaxed;
        }

        //https://www.geeksforgeeks.org/bipartite-graph/

        bool isBipartiteUtil(const std::vector<std::vector<int>>& graph, std::vector<int>& color, int start) {
            size_t n = graph.size();
            std::queue<int> q;

            q.push(start);
            color[static_cast<size_t>(start)] = 0;

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (size_t v = 0; v < n; ++v) {
                    if (graph[static_cast<size_t>(u)][static_cast<size_t>(v)]) {
                        if (color[v] == -1) {
                            color[static_cast<size_t>(v)] = 1 - color[static_cast<size_t>(u)];
                            q.push(v);
                        } else if (color[static_cast<size_t>(v)] == color[static_cast<size_t>(u)]) {
                            return false;
                        }
                    }
                }
            }

            return true;
        }


    }

    bool Algorithms::isConnected(const Graph& g) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<bool> visited(n, false);

        dfs(graph, visited, 0);
        return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }

    std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> prev(n, -1);

        dist[static_cast<size_t>(start)] = 0;
        for (size_t i = 0; i < n - 1; ++i) {
            if (!relaxEdges(graph, dist, prev)) {
                break;
            }
        }

        if (dist[static_cast<size_t>(end)] == std::numeric_limits<int>::max()) {
            return "-1";
        }

        std::string path = std::to_string(end);
        int cur = end;
        while (prev[static_cast<size_t>(cur)] != -1) {
            path = std::to_string(prev[static_cast<size_t>(cur)]) + "->" + path;
            cur = prev[static_cast<size_t>(cur)];
        }
        return path;
    }

    bool Algorithms::isContainsCycle(const Graph& g) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<bool> visited(n, false);
        std::vector<bool> recStack(n, false);

        for (size_t i = 0; i < n; ++i) {
            if (hasCycle(graph, visited, recStack, i)) {
                return true;
            }
        }

        return false;
    }

    std::string Algorithms::isBipartite(const Graph& g) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<int> color(n, -1);

        for (size_t i = 0; i < n; ++i) {
            if (color[i] == -1 && !isBipartiteUtil(graph, color, i)) {
                return "0"; // Not bipartite
            }
        }

        std::unordered_map<int, std::vector<int>> partition;
        for (size_t i = 0; i < n; ++i) {
            partition[color[i]].push_back(i);
        }

        std::ostringstream oss;
        oss << "The graph is bipartite: A={";
        for (int vertex : partition[0]) oss << vertex << ", ";
        if (!partition[0].empty()) oss.seekp(-2, std::ios_base::end);
        oss << "}, B={";
        for (int vertex : partition[1]) oss << vertex << ", ";
        if (!partition[1].empty()) oss.seekp(-2, std::ios_base::end);
        oss << "}";
        std::string result = oss.str();
        return result;
    }

    bool Algorithms::negativeCycle(const Graph& g) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> prev(n, -1);

        int source = 0;        // Start with an arbitrary vertex
        dist[static_cast<size_t>(source)] = 0;        // Initialize distances
        // Relax edges repeatedly until no more relaxation can be done
        for (size_t i = 0; i < n - 1; ++i) {
            if (!relaxEdges(graph, dist, prev)) {
                break;
            }
        }

        // Check for negative cycles
        bool hasCycle = relaxEdges(graph, dist, prev);
        if (hasCycle) {
            std::cout << "Negative cycle detected!" << std::endl;
        } else {
            std::cout << "No negative cycle detected." << std::endl;
        }
            
        return hasCycle;
    }

} // namespace ariel
