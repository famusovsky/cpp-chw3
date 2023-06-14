// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <string>
#include <fstream>

std::fstream createFile(const std::string& path) {
    std::fstream file;
    file.open(path, std::ios::out);
    file.precision(2);
    file << std::fixed;
    return file;
}
