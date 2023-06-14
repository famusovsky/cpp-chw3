#include <cstdint>
#include <vector>
#include <climits>

// Function to perform Bellman-Ford algorithm
void bellmanFord(const std::vector<std::vector<int64_t>>& graph) {
    int64_t source = 0;
    int64_t num_nodes = graph.size();

    // Create a vector to store the shortest distances from the source node
    std::vector<int64_t> distances(num_nodes, INT64_MAX);

    // Mark the distance of the source node as 0
    distances[source] = 0;

    // Relax the edges repeatedly
    for (int64_t i = 0; i < num_nodes - 1; i++) {
        for (int64_t u = 0; u < num_nodes; u++) {
            for (int64_t v = 0; v < num_nodes; v++) {
                int64_t weight = graph[u][v];

                if (distances[u] != INT64_MAX && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int64_t u = 0; u < num_nodes; u++) {
        for (int64_t v = 0; v < num_nodes; v++) {
            int64_t weight = graph[u][v];

            if (distances[u] != INT64_MAX && distances[u] + weight < distances[v]) {
                return;
            }
        }
    }

    // end of bellmanFord algorithm
}