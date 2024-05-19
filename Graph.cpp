//5249
//itamar.shpitzer@msmail.ariel.ac.il

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>
#include <sstream>


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


    std::string Graph::printGraph() const {
        std::stringstream ss;
        ss << *this;
        std::string str = ss.str();
        str.pop_back();
        return str;
    }

    const std::vector<std::vector<int>>& Graph::getAdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    // addition
    Graph Graph::operator+(const Graph& other) const {
        if (adjacencyMatrix.size() != other.adjacencyMatrix.size() || 
            adjacencyMatrix[0].size() != other.adjacencyMatrix[0].size()) {
            throw std::invalid_argument("Matrices must have the same dimensions for addition");
        }

        Graph result;
        std::vector<std::vector<int>> resultMatrix(adjacencyMatrix.size(), std::vector<int>(adjacencyMatrix[0].size()));

        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[0].size(); ++j) {
                resultMatrix[i][j] = adjacencyMatrix[i][j] + other.adjacencyMatrix[i][j];
            }
        }

        result.loadGraph(resultMatrix);
        return result;
    }

    // subtraction
    Graph Graph::operator-(const Graph& other) const {
        return *this + (-other);
    }

    // multiplication by scalar
    Graph Graph::operator*(const int scalar) const {
        Graph result;
        std::vector<std::vector<int>> resultMatrix(adjacencyMatrix.size(), std::vector<int>(adjacencyMatrix[0].size()));

        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[0].size(); ++j) {
                resultMatrix[i][j] = adjacencyMatrix[i][j] * scalar;
            }
        }

        result.loadGraph(resultMatrix);
        return result;
    }

    // matrix multiplication
    Graph Graph::operator*(const Graph& other) const {
        if (adjacencyMatrix.size() != other.adjacencyMatrix.size() || 
            adjacencyMatrix[0].size() != other.adjacencyMatrix[0].size()) {
            throw std::invalid_argument("Matrices must have the same dimensions for graph multiplication");
        }

        Graph result;
        std::vector<std::vector<int>> resultMatrix(adjacencyMatrix.size(), std::vector<int>(adjacencyMatrix[0].size()));

        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[0].size(); ++j) {
                if(i == j ){
                    resultMatrix[i][j] = 0;
                    continue;
                }
                for (size_t k = 0; k < adjacencyMatrix[0].size(); ++k) {

                    resultMatrix[i][j] += adjacencyMatrix[i][k] * other.adjacencyMatrix[k][j];
                }
            }
        }

        result.loadGraph(resultMatrix);
        return result;
    }

    // add to all graph
    Graph Graph::operator+(const int scalar) const {
        Graph result;
        std::vector<std::vector<int>> resultMatrix(adjacencyMatrix.size(), std::vector<int>(adjacencyMatrix[0].size()));

        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[0].size(); ++j) {
                if (adjacencyMatrix[i][j] != 0){
                    resultMatrix[i][j] = adjacencyMatrix[i][j] + scalar;
                }
            }
        }

        result.loadGraph(resultMatrix);
        return result;
    }
    Graph Graph::operator-(const int scalar) const {
        return (*this) + (-scalar);

    }


    // Function to increase all edge weights by 1 (++graph)
    Graph& Graph::operator++() {
        *this = *this + 1;
        return *this;
    }

    // Function to decrease all edge weights by 1 (--graph)
    Graph& Graph::operator--() {
        *this = *this - 1;
        return *this;
    }

    // Function to add a given number to all edges of the graph (graph++)
    Graph Graph::operator++(int) {
        Graph result(*this); // Create a copy of the current graph
        ++(*this); // Increment the current graph
        return result; // Return the original graph
    }

    // Function to subtract a given number from all edges of the graph (graph--)
    Graph Graph::operator--(int) {
        Graph result(*this); // Create a copy of the current graph
        --(*this); // Decrement the current graph
        return result; // Return the original graph
    }
    Graph operator+(const int scalar, const Graph& matrix) {
        return matrix + scalar;
    }
    Graph operator-(const int scalar, const Graph& matrix) {
        return matrix - scalar;
    }

    // unary plus operator
    Graph Graph::operator+() const {
        return *this;
    }

    // unary minus operator
    Graph Graph::operator-() const {
        return (*this) * (-1);
    }

    // addition assignment
    Graph& Graph::operator+=(const Graph& other) {
        *this = *this + other;
        return *this;
    }

    // subtraction assignment
    Graph& Graph::operator-=(const Graph& other) {
        *this = *this - other;
        return *this;
    }

    Graph operator*(const int scalar, const Graph& matrix) {
        return matrix * scalar;
    }

    bool Graph::operator>(const Graph& other) const {
        // Compare number of edges
        int edgesThis = 0;
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                edgesThis += (adjacencyMatrix[i][j] != 0);
            }
        }
        int edgesOther = 0;
        for (size_t i = 0; i < other.adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < other.adjacencyMatrix[i].size(); ++j) {
                edgesOther += (other.adjacencyMatrix[i][j] != 0);
            }
        }

        if (edgesThis != edgesOther) {
            return edgesThis > edgesOther; // Graph with more edges is greater
        }
        // Compare order of magnitude
        return adjacencyMatrix.size() > other.adjacencyMatrix.size();
    }

    bool Graph::operator==(const Graph& other) const {
        return (!(other > *this)) && (!(*this > other));
    }

    bool Graph::operator>=(const Graph& other) const {
        return (*this == other) || (*this > other);
    }

    bool Graph::operator<(const Graph& other) const {
        return !(*this >= other);
    }

    bool Graph::operator<=(const Graph& other) const {
        return !(*this > other);
    }

    bool Graph::operator!=(const Graph& other) const {
        return !(*this == other);    
    }

    std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        const auto& adjacencyMatrix = graph.adjacencyMatrix;
        for (const auto& row : adjacencyMatrix) {
            os << "[";
            for (size_t i = 0; i < row.size(); ++i) {
                os << row[i];
                if (i != row.size() - 1)
                    os << ", ";
            }
            os << "]\n";
        }
        return os;
    }

}
