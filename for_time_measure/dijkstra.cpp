#include <iostream>
#include <vector>
#include <queue>
#include <climits>

void dijkstra(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    int source = 0;
    std::vector<int> dist(n, INT_MAX);
    std::vector<bool> visited(n, false);

    dist[source] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            int weight = graph[u][v];

            if (!visited[v] && dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
}