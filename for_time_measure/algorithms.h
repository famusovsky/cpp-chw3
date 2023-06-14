// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <vector>
#include <string>

/// Dijkstra's algorithm for finding the shortest paths from a single node to all other nodes in a weighted graph.
/// \param graph - adjacency matrix of the graph
void dijkstra(const std::vector<std::vector<int64_t>>& graph);

/// Floyd-Warshall algorithm for finding the shortest paths between all pairs of vertices in a weighted graph.
/// \param graph - adjacency matrix of the graph
void floydWarshall(const std::vector<std::vector<int64_t>>& graph);

/// Bellman-Ford algorithm for finding the shortest paths from a single node to all other nodes in a weighted graph.
/// \param graph - adjacency matrix of the graph
void bellmanFord(const std::vector<std::vector<int64_t>>& graph);