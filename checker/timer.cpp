// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <vector>
#include <string>
#include <chrono>

#include <iostream>

#include "graph-getter.h"

const int MIN_CNT_NODES = 10;
const int MAX_CNT_NODES = 1010;
const int STEP_NODES = 50;

std::vector<std::vector<int64_t>> timerForNodes(void (*func)(const std::vector<std::vector<int64_t>>&), std::string path) {
    std::vector<std::vector<int64_t>> times((MAX_CNT_NODES - MIN_CNT_NODES) / STEP_NODES + 1, std::vector<int64_t>(5));

    for (int n = MIN_CNT_NODES; n <= MAX_CNT_NODES; n += STEP_NODES) {
        Graph graph = getGraph(path + std::to_string(n) + ".txt");

        std::cout << '\n' << n << '\n';

        std::vector<int64_t> time(5);

        for (size_t i = 0; i < time.size(); i++) {
            auto start = std::chrono::high_resolution_clock::now();
            func(graph.matrix);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            int64_t nanoseconds =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            time[i] = nanoseconds;

            std::cout << i << ' ';
        }
        
        times[(n - MIN_CNT_NODES) / STEP_NODES] = time;
    }

    return times;
}

std::vector<std::pair<int, std::vector<int64_t>>> timerForEdges(void (*func)(const std::vector<std::vector<int64_t>>&), std::string path) {
    std::vector<std::pair<int, std::vector<int64_t>>> times;
    
    for (int n = MIN_CNT_NODES; n <= MAX_CNT_NODES; n += STEP_NODES) {
        Graph graph = getGraph(path + std::to_string(n) + ".txt");

        std::cout << '\n' << n << '\n';

        std::vector<int64_t> time(5);

        for (size_t i = 0; i < time.size(); i++) {
            auto start = std::chrono::high_resolution_clock::now();
            func(graph.matrix);
            auto elapsed = std::chrono::high_resolution_clock::now() - start;
            int64_t nanoseconds =
                std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();
            time[i] = nanoseconds;

            std::cout << i << ' ';
        }

        times.push_back(std::make_pair(graph.edges, time));
    }
    return times;
}
