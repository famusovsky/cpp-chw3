// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <fstream>
#include <sstream>
#include <string>
#include "graph-getter.h"

Graph getGraph(const std::string& path) {
    std::fstream file;
    file.open(path, std::ios::in);
    std::string result;
    std::string line;
    while (getline(file, line)) {
        result += line + '\n';
    }
    file.close();

    std::stringstream ss(result);
    Graph graph;
    ss >> graph.nodes >> graph.edges;
    for (int i = 0; i < graph.nodes; ++i) {
        std::vector<int64_t> row;
        for (int j = 0; j < graph.nodes; ++j) {
            int64_t value;
            ss >> value;
            row.push_back(value);
        }
        graph.matrix.push_back(row);
    }

    return graph;
}