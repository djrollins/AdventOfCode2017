add_compile_options(${COMPILER_WARNINGS})

add_executable(spiral main.cpp spiral.cpp)
target_compile_features(spiral PRIVATE cxx_std_17)

add_executable(spiral_test tests/spiral_test.cpp spiral.cpp)
target_link_libraries(spiral_test test_runner)
target_compile_features(spiral_test PRIVATE cxx_std_17)

add_test(spiral_test spiral_test)
