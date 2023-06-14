// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <fstream>
#include <string>
#include <vector>
#include "for_time_measure/algorithms.h"
#include "checker/functions.h"
#include "task_execution/functions.h"

int main() {
    srand(time(nullptr));

    std::vector<void (*)(const std::vector<std::vector<int64_t>>&)> functions = {
        &dijkstra, &floydWarshall, &bellmanFord};

    std::vector<std::string> names = {"dijkstra", "floydWarshall", "bellmanFord"};

    std::vector<std::string> input_pathes = {"../data/graphs/complete_",
                                             "../data/graphs/connected_", "../data/graphs/sparse_"};

    std::fstream file;

    int x = 0;

    file = createFile("../data/output/time_nodes.csv");
    runTimeToFileForNodes(functions, names, input_pathes, file);
    file.close();

    file = createFile("../data/output/time_edges.csv");
    runTimeToFileForEdges(functions, names, input_pathes, file);
    file.close();

    return 0;
}
