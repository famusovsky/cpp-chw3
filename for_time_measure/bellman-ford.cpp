#include <vector>
#include <climits>

// Function to perform Bellman-Ford algorithm
void bellmanFord(const std::vector<std::vector<int>>& graph) {
    int source = 0;
    int num_nodes = graph.size();

    // Create a vector to store the shortest distances from the source node
    std::vector<int> distances(num_nodes, INT_MAX);

    // Mark the distance of the source node as 0
    distances[source] = 0;

    // Relax the edges repeatedly
    for (int i = 0; i < num_nodes - 1; i++) {
        for (int u = 0; u < num_nodes; u++) {
            for (int v = 0; v < num_nodes; v++) {
                int weight = graph[u][v];

                if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < num_nodes; u++) {
        for (int v = 0; v < num_nodes; v++) {
            int weight = graph[u][v];

            if (distances[u] != INT_MAX && distances[u] + weight < distances[v]) {
                return;
            }
        }
    }

    // end of bellmanFord algorithm
}