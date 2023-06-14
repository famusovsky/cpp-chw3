// АиСД-2, 2023, КДЗ-3
// Степанов А, БПИ212

#include <vector>
#include <string>

/// Метод, измеряющий время работы данных алгоритмов для каждого количества вершин и записывающий результаты в файл
/// \param functions - вектор функций, время работы которых нужно измерить
/// \param names - вектор имен функций
/// \param pathes - вектор путей к файлам, в которых хранится исходный текст
/// \param file - файл, в который нужно записать результаты
void runTimeToFileForNodes(std::vector<void (*)(const std::vector<std::vector<int64_t>> &)> functions,
                   std::vector<std::string> names, std::vector<std::string> pathes,
                   std::fstream &file);

/// Метод, измеряющий время работы данных алгоритмов для каждого количества рёбер и записывающий результаты в файл
/// \param functions - вектор функций, время работы которых нужно измерить
/// \param names - вектор имен функций
/// \param pathes - вектор путей к файлам, в которых хранится исходный текст
/// \param file - файл, в который нужно записать результаты
void runTimeToFileForEdges(std::vector<void (*)(const std::vector<std::vector<int64_t>> &)> functions,
                   std::vector<std::string> names, std::vector<std::string> pathes,
                   std::fstream &file);

/// Метод, создающий файл
/// \param path - путь к файлу
/// \return - созданный файл
std::fstream createFile(const std::string &path);