#include <fstream>
#include <iostream>
#include "fmt/core.h"

int main() {
    static constexpr const char* FILE_PATH_ENV = "AOC_FILE_PATH";
    char *base_file_path = std::getenv(FILE_PATH_ENV);

    if (base_file_path == nullptr) {
        fmt::println("Set the AOC_FILE_PATH environment variable for the path where to read files from, you muppet!");
        return EXIT_FAILURE;
    }

    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));
        return EXIT_FAILURE;
    }

    std::string line;

    while (std::getline(file, line)) {
        fmt::println("{}", line);
    }

    return 0;
}
