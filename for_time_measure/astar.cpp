#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

// Structure to represent a node in the graph
struct Node {
    int64_t x;  // x-coordinate of the node
    int64_t y;  // y-coordinate of the node
    int64_t f;  // f-score of the node (f = g + h)
    int64_t g;  // g-score of the node
    int64_t h;  // h-score of the node

    Node(int64_t x, int64_t y, int64_t f, int64_t g, int64_t h) : x(x), y(y), f(f), g(g), h(h) {
    }

    bool operator<(const Node& other) const {
        return f > other.f;
    }
};

// Function to check if a given position is valid
bool isValid(int64_t x, int64_t y, int64_t rows, int64_t cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

// Function to calculate the Manhattan distance heuristic
int64_t calculateH(int64_t x, int64_t y, int64_t target_x, int64_t target_y) {
    return abs(target_x - x) + abs(target_y - y);
}

// Function to find the shortest path using A* algorithm
void aStar(const std::vector<std::vector<int64_t>>& graph) {
    int64_t rows = graph.size();
    int64_t cols = graph[0].size();

    int64_t start_x = 0;
    int64_t start_y = 0;
    int64_t target_x = rows - 1;
    int64_t target_y = cols - 1;

    std::vector<std::pair<int64_t, int64_t>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    std::priority_queue<Node> pq;

    std::vector<std::vector<int64_t>> g_score(rows, std::vector<int64_t>(cols, INT64_MAX));
    std::vector<std::vector<int64_t>> f_score(rows, std::vector<int64_t>(cols, INT64_MAX));
    std::vector<std::vector<std::pair<int64_t, int64_t>>> parent(
        rows, std::vector<std::pair<int64_t, int64_t>>(cols, {-1, -1}));

    pq.push(Node(start_x, start_y, 0, 0, 0));
    g_score[start_x][start_y] = 0;
    f_score[start_x][start_y] = calculateH(start_x, start_y, target_x, target_y);

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        int64_t x = curr.x;
        int64_t y = curr.y;

        if (x == target_x && y == target_y) {
            // Reconstruct the path
            std::vector<std::pair<int64_t, int64_t>> path;
            while (x != start_x || y != start_y) {
                path.push_back({x, y});
                int64_t px = parent[x][y].first;
                int64_t py = parent[x][y].second;
                x = px;
                y = py;
            }
            path.push_back({start_x, start_y});
            std::reverse(path.begin(), path.end());
            return;
        }

        for (const auto& dir : directions) {
            int64_t nx = x + dir.first;
            int64_t ny = y + dir.second;

            if (isValid(nx, ny, rows, cols) && graph[nx][ny] == 0) {
                int64_t new_g_score = g_score[x][y] + 1;
                int64_t new_f_score = new_g_score + calculateH(nx, ny, target_x, target_y);

                if (new_f_score < f_score[nx][ny]) {
                    pq.push(Node(nx, ny, new_f_score, new_g_score,
                                 calculateH(nx, ny, target_x, target_y)));
                    parent[nx][ny] = {x, y};
                    g_score[nx][ny] = new_g_score;
                    f_score[nx][ny] = new_f_score;
                }
            }
        }
    }
}