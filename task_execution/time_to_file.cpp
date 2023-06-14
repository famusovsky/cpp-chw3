// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <sys/_types/_int64_t.h>
#include <ostream>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

#include <iostream>
#include "../checker/functions.h"

void runTimeToFileForNodes(
    std::vector<void (*)(const std::vector<std::vector<int64_t>> &)> functions,
    std::vector<std::string> names, std::vector<std::string> pathes, std::fstream &file) {
    std::regex pattern("([^/]+)(?=_$)");

    for (size_t i = 0; i < functions.size(); ++i) {
        for (size_t j = 0; j < pathes.size(); ++j) {
            std::smatch match;
            file << (std::regex_search(pathes[j], match, pattern) ? match.str() + " - " : "") <<  names[i];
            
            void (*func)(const std::vector<std::vector<int64_t>> &) = functions[i];
            std::vector<std::vector<int64_t>> times = timerForNodes(func, pathes[j]);

            for (size_t z = 0; z < times.size(); ++z) {
                double average = 0;

                for (size_t k = 0; k < times[z].size(); ++k) {
                    average += times[z][k];
                }
                average /= static_cast<double>(times[z].size());

                file << ";" << average;
            }

            file << std::endl;

            std::cout << functions[i] << ' ' << pathes[j] << " done\n";
        }
    }

    file.close();
}

void runTimeToFileForEdges(
    std::vector<void (*)(const std::vector<std::vector<int64_t>> &)> functions,
    std::vector<std::string> names, std::vector<std::string> pathes, std::fstream &file) {
    std::regex pattern("([^/]+)(?=_$)");

    for (size_t i = 0; i < functions.size(); ++i) {
        for (size_t j = 0; j < pathes.size(); ++j) {
            std::smatch match;
            file << (std::regex_search(pathes[j], match, pattern) ? match.str() + " - " : "") <<  names[i];
            
            void (*func)(const std::vector<std::vector<int64_t>> &) = functions[i];
            std::vector<std::pair<int, std::vector<int64_t>>> times = timerForEdges(func, pathes[j]);
            
            std::sort(times.begin(), times.end(), [](const std::pair<int, std::vector<int64_t>>& a, const std::pair<int, std::vector<int64_t>>& b) {
                return a.first < b.first;
            });

            for (size_t z = 0; z < times.size(); ++z) {
                double average = 0;
                int x;
                for (size_t k = 0; k < times[z].second.size(); ++k) {
                    average += times[z].second[k];
                }
                average /= static_cast<double>(times[z].second.size());
                file << ";" << average;
            }

            file << std::endl;

            std::cout << functions[i] << ' ' << pathes[j] << " done\n";
        }
    }
    file.close();
}

