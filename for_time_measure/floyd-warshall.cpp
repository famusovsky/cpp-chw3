#include <iostream>
#include <vector>
#include <climits>

// Function to perform Floyd-Warshall algorithm
void floydWarshall(const std::vector<std::vector<int>>& graph) {
    int num_nodes = graph.size();

    // Create a 2D matrix to store the shortest distances between all pairs of nodes
    std::vector<std::vector<int>> distances(graph);

    // Initialize the distances with the values from the graph
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            if (graph[i][j] == 0 && i != j) {
                distances[i][j] = INT_MAX; // Set non-connected nodes to infinity
            }
        }
    }

    // Perform the Floyd-Warshall algorithm
    for (int k = 0; k < num_nodes; k++) {
        for (int i = 0; i < num_nodes; i++) {
            for (int j = 0; j < num_nodes; j++) {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    // end of floydWarshall algorithm
}
