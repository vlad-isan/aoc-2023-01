//
// Created by Vlad Isan on 05/12/2023.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include "fmt/core.h"
#include <vector>

int puzzle_sample_1(std::string base_file_path);
int puzzle_sample_2(std::string base_file_path);
int puzzle_1(std::string base_file_path);
int puzzle_2(std::string base_file_path);

int do_puzzle_1(std::ifstream &file);
int do_puzzle_2(std::ifstream &file);

template <typename T>
concept StringIterator = std::same_as<T, std::string::iterator> || std::same_as<T, std::string::reverse_iterator>;

template<StringIterator T>
std::string get_uber_digit(const T &first_iterator, const T &last_iterator, bool should_reverse = false);

#endif //PUZZLE_H
