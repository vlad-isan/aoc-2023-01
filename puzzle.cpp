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

    return do_puzzle_1(file);
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

    return do_puzzle_2(file);
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

    return do_puzzle_1(file);
}

int puzzle_2(std::string base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int do_puzzle_1(std::ifstream &file) {
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

int do_puzzle_2(std::ifstream &file) {
    std::string line;
    uint32_t value = 0;

    while (std::getline(file, line)) {
        auto first_digit = get_uber_digit(line.begin(), line.end());
        auto last_digit = get_uber_digit(line.rbegin(), line.rend(), true);

        auto number_string = fmt::format("{}{}", first_digit, last_digit);
        value += std::stoi(number_string);
    }

    fmt::println("Total is {}", value);

    return value;
}

static const std::vector<std::string> digit_words = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
};

// gets first digit in string, either digit or spelled out with letters
template<StringIterator T>
std::string get_uber_digit(const T &first_it, const T &last_it, bool should_reverse) {
    std::string digit{0};

    auto first_digit = std::find_if(first_it, last_it, [](char c) { return std::isdigit(c); });

    if (first_digit != last_it) {
        digit = *first_digit;
    }

    const auto really_last_it = first_digit != last_it ? first_digit : last_it;

    size_t index = 0;
    auto min_iter = really_last_it;
    auto min_index = 0;

    for (const auto &digit_word_const: digit_words) {
        std::string digit_word = digit_word_const;

        if (should_reverse) {
            std::reverse(digit_word.begin(), digit_word.end());
        }

        if (const auto it = std::search(first_it, really_last_it, digit_word.begin(), digit_word.end());
            it != really_last_it) {

            if (std::distance(it, min_iter) > 0) {
                min_iter = it;
                min_index = index;
            }
        }

        ++index;
    }

    if (first_digit != last_it && std::distance(first_it, first_digit) <= std::distance(first_it, min_iter)) {
        digit = *first_digit;
    }
    else {
        digit = std::to_string(min_index);
    }

    return digit;
}
