cmake_minimum_required(VERSION 3.6)

project(advent-of-code)

add_library(test_runner common/test_runner.cpp)
target_include_directories(test_runner PUBLIC lib/catch/single_include)
target_compile_features(test_runner PUBLIC cxx_std_11)

enable_testing()
