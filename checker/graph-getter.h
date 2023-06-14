// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <string>
#include <vector>

/// Structure which represents graph.
/// nodes - number of nodes in graph.
/// edges - number of edges in graph.
/// matrix - adjacency matrix of graph.
struct Graph {
    int nodes;
    int edges;
    std::vector<std::vector<int>> matrix;
};

/// Function which returns graph from file.
/// \param path Path to file.
/// \return Graph from file.
Graph getGraph(const std::string& path);
