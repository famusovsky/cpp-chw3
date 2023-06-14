#include <iostream>
#include <vector>
#include <queue>
#include <climits>

void dijkstra(const std::vector<std::vector<int64_t>>& graph) {
    int64_t n = graph.size();
    int64_t source = 0;
    std::vector<int64_t> dist(n, INT64_MAX);
    std::vector<bool> visited(n, false);

    dist[source] = 0;

    std::priority_queue<std::pair<int64_t, int64_t>, std::vector<std::pair<int64_t, int64_t>>, std::greater<std::pair<int64_t, int64_t>>> pq;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        int64_t u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (int64_t v = 0; v < n; ++v) {
            int64_t weight = graph[u][v];

            if (!visited[v] && dist[u] != INT64_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v], v));
            }
        }
    }
}