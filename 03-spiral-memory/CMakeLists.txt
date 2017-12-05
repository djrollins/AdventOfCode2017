add_executable(spiral spiral.cpp)
target_compile_features(spiral PRIVATE cxx_std_17)

add_executable(spiral_test tests/spiral_test.cpp)
target_link_libraries(spiral_test test_runner)
add_test(spiral_test spiral_test)
target_compile_features(spiral_test PRIVATE cxx_std_17)
