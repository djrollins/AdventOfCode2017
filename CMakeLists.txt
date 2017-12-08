cmake_minimum_required(VERSION 3.6)

project(advent-of-code)

add_library(test_runner common/test_runner.cpp)
target_include_directories(test_runner PUBLIC lib/catch/single_include)
target_compile_features(test_runner PUBLIC cxx_std_11)

enable_testing()

set(COMPILER_WARNINGS -Wall -Wextra -pedantic)
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(COMPILER_WARNINGS ${COMPILER_WARNINGS} -Weverything -Wno-c++98-compat)
endif()


add_subdirectory(01-inverse-captcha)
add_subdirectory(02-corruption-checksum)
add_subdirectory(03-spiral-memory)
add_subdirectory(04-passphrases)
add_subdirectory(05-jumps)
