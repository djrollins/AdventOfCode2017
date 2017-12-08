add_compile_options(${COMPILER_WARNINGS})

add_executable(checksum main.cpp checksum.cpp)
target_compile_features(checksum PRIVATE cxx_std_17)

add_executable(checksum_test tests/checksum_test.cpp checksum.cpp)
target_link_libraries(checksum_test test_runner)
target_compile_features(checksum_test PRIVATE cxx_std_17)

add_test(checksum_test checksum_test)
