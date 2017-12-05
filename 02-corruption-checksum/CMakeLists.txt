add_executable(checksum checksum.cpp)
target_compile_features(checksum PRIVATE cxx_std_17)

add_executable(checksum_test tests/checksum_test.cpp)
target_link_libraries(checksum_test test_runner)
add_test(checksum_test checksum_test)
target_compile_features(checksum_test PRIVATE cxx_std_17)
