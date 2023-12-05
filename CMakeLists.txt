cmake_minimum_required(VERSION 3.27)
project(aoc-template)

set(CMAKE_CXX_STANDARD 23)

find_package(fmt CONFIG REQUIRED)

add_executable(aoc-template main.cpp)

target_link_libraries(aoc-template
        PUBLIC
        fmt::fmt
)
