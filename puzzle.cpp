//
// Created by Vlad Isan on 05/12/2023.
//

#include "puzzle.h"

int puzzle_sample_1(std::string base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    std::string line;
    uint32_t value = 0;

    while (std::getline(file, line)) {
        auto first_digit = std::ranges::find_if(line, [](char c) { return std::isdigit(c); });
        auto last_digit = std::ranges::find_if(line | std::views::reverse, [](char c) { return std::isdigit(c); });

        if (first_digit != line.end() && last_digit != line.rend()) {
            auto number_string = fmt::format("{}{}", *first_digit, *last_digit);
            value += std::stoi(number_string);
        }
    }

    fmt::println("Total is {}", value);

    return value;
}

int puzzle_sample_2(std::string base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    std::string line;
    uint32_t value = 0;

    while (std::getline(file, line)) {
        auto first_digit = std::ranges::find_if(line, [](char c) { return std::isdigit(c); });
        auto last_digit = std::ranges::find_if(line | std::views::reverse, [](char c) { return std::isdigit(c); });

        if (first_digit != line.end() && last_digit != line.rend()) {
            auto number_string = fmt::format("{}{}", *first_digit, *last_digit);
            value += std::stoi(number_string);
        }
    }

    fmt::println("Total is {}", value);

    return value;
}

int puzzle_1(std::string base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    std::string line;
    uint32_t value = 0;

    while (std::getline(file, line)) {
        auto first_digit = std::ranges::find_if(line, [](char c) { return std::isdigit(c); });
        auto last_digit = std::ranges::find_if(line | std::views::reverse, [](char c) { return std::isdigit(c); });

        if (first_digit != line.end() && last_digit != line.rend()) {
            auto number_string = fmt::format("{}{}", *first_digit, *last_digit);
            value += std::stoi(number_string);
        }
    }

    fmt::println("Total is {}", value);

    return value;
}
