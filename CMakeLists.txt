cmake_minimum_required(VERSION 3.27)
project(OOP_5_1_E)

set(CMAKE_CXX_STANDARD 17)

add_executable(OOP_5_1_E main.cpp
        Object.cpp
        LongLong.cpp
)

add_subdirectory(Google_tests)
