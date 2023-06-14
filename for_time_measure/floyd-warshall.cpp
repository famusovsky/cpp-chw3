#include <cstdint>
#include <iostream>
#include <vector>
#include <climits>

// Function to perform Floyd-Warshall algorithm
void floydWarshall(const std::vector<std::vector<int64_t>>& graph) {
    int64_t num_nodes = graph.size();

    // Create a 2D matrix to store the shortest distances between all pairs of nodes
    std::vector<std::vector<int64_t>> distances(graph);

    // Initialize the distances with the values from the graph
    for (int64_t i = 0; i < num_nodes; i++) {
        for (int64_t j = 0; j < num_nodes; j++) {
            if (graph[i][j] == 0 && i != j) {
                distances[i][j] = INT64_MAX; // Set non-connected nodes to infinity
            }
        }
    }

    // Perform the Floyd-Warshall algorithm
    for (int64_t k = 0; k < num_nodes; k++) {
        for (int64_t i = 0; i < num_nodes; i++) {
            for (int64_t j = 0; j < num_nodes; j++) {
                if (distances[i][k] != INT64_MAX && distances[k][j] != INT64_MAX &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    // end of floydWarshall algorithm
}
