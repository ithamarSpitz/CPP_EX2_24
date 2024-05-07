//algorithms.cpp

#include "Algorithms.hpp"
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <functional>
#include <iostream>

namespace ariel {

    bool Algorithms::isConnected(const Graph& g) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<bool> visited(n, false);

        std::function<void(int)> dfs = [&](int v) {
            visited[static_cast<size_t>(v)] = true;
            for (size_t u = 0; u < n; ++u) {
                if (graph[static_cast<size_t>(v)][static_cast<size_t>(u)] && !visited[static_cast<size_t>(u)]) {
                    dfs(u);
                }
            }
        };

        dfs(0);
        return std::all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }

    std::string Algorithms::shortestPath(const Graph& g, int start, int end) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> prev(n, -1);

        dist[static_cast<size_t>(start)] = 0;
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t u = 0; u < n; ++u) {
                for (size_t v = 0; v < n; ++v) {
                    if (graph[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                        prev[v] = u;
                    }
                }
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

        std::function<bool(int)> dfs = [&](int v) {
            if (!visited[static_cast<size_t>(v)]) {
                visited[static_cast<size_t>(v)] = true;
                recStack[static_cast<size_t>(v)] = true;

                for (size_t u = 0; u < n; ++u) {
                    if (graph[static_cast<size_t>(v)][static_cast<size_t>(u)]) {
                        if (!visited[static_cast<size_t>(u)] && dfs(u)) {
                            return true;
                        } else if (recStack[static_cast<size_t>(u)]) {
                            return true;
                        }
                    }
                }
            }
            recStack[static_cast<size_t>(v)] = false;
            return false;
        };

        for (size_t i = 0; i < n; ++i) {
            if (dfs(i)) {
                return true;
            }
        }

        return false;
    }

    std::string Algorithms::isBipartite(const Graph& g) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<int> color(n, -1);
        std::queue<int> q;

        for (size_t i = 0; i < n; ++i) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (size_t v = 0; v < n; ++v) {
                        if (graph[static_cast<size_t>(u)][static_cast<size_t>(v)]) {
                            if (color[v] == -1) {
                                color[static_cast<size_t>(v)] = 1 - color[static_cast<size_t>(u)];
                                q.push(v);
                            } else if (color[static_cast<size_t>(v)] == color[static_cast<size_t>(u)]) {
                                return "0";
                            }
                        }
                    }
                }
            }
        }

        std::unordered_map<int, std::vector<int>> partition;
        for (size_t i = 0; i < n; ++i) {
            partition[color[i]].push_back(i);
        }

        std::string result = "The graph is bipartite: ";
        result += "A={";
        for (int vertex : partition[0]) {
            result += std::to_string(vertex) + ", ";
        }
        result.pop_back();
        result.pop_back();
        result += "}, B={";
        for (int vertex : partition[1]) {
            result += std::to_string(vertex) + ", ";
        }
        result.pop_back();
        result.pop_back();
        result += "}";
        return result;
    }

    bool Algorithms::negativeCycle(const Graph& g) {
        const std::vector<std::vector<int>>& graph = g.getAdjacencyMatrix();
        size_t n = graph.size();
        std::vector<int> dist(n, std::numeric_limits<int>::max());
        std::vector<int> prev(n, -1);

        // Start with an arbitrary vertex
        int source = 0;

        // Initialize distances
        dist[static_cast<size_t>(source)] = 0;

        // Relax edges repeatedly
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t u = 0; u < n; ++u) {
                for (size_t v = 0; v < n; ++v) {
                    if (graph[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                        dist[v] = dist[u] + graph[u][v];
                        prev[v] = u;
                    }
                }
            }
        }

        // Check for negative cycles
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < n; ++v) {
                if (graph[u][v] != 0 && dist[u] != std::numeric_limits<int>::max() && dist[u] + graph[u][v] < dist[v]) {
                    std::cout << "Negative cycle detected!" << std::endl;
                    return true;
                }
            }
        }

        std::cout << "No negative cycle detected." << std::endl;
        return false;
    }

} // namespace ariel
