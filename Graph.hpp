//5249
//itamar.shpitzer@msmail.ariel.ac.il

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
        std::string printGraph() const;

        // Get the adjacency matrix
        const std::vector<std::vector<int>>& getAdjacencyMatrix() const;

                // Addition operator
        Graph operator+(const Graph& other) const;

        // Subtraction operator
        Graph operator-(const Graph& other) const;

        // Multiplication by scalar
        Graph operator*(const int scalar) const;

        // Graph multiplication
        Graph operator*(const Graph& other) const;

        // Unary plus operator
        Graph operator+() const;

        // Unary minus operator
        Graph operator-() const;

        // Addition assignment operator
        Graph& operator+=(const Graph& other);

        // Subtraction assignment operator
        Graph& operator-=(const Graph& other);
        // Friend function for scalar operations
        friend Graph operator*(const int scalar, const Graph& matrix); // Multiplication
        // Friend function for scalar operations
        friend Graph operator+(const int scalar, const Graph& matrix); // addition
        // Friend function for scalar operations
        friend Graph operator-(const int scalar, const Graph& matrix); // Subtraction
        // Comparison operators
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;

        Graph operator+(const int scalar) const;
        Graph operator-(const int scalar) const;

        // Function to increase all edge weights by 1 (++graph)
        Graph& operator++();

        // Function to decrease all edge weights by 1 (--graph)
        Graph& operator--();

        // Function to add a given number to all edges of the graph (graph++)
        Graph operator++(int);

        // Function to subtract a given number from all edges of the graph (graph--)
        Graph operator--(int);

        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);
    };

}

#endif // GRAPH_HPP
