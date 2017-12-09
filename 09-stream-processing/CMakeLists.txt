add_compile_options(${COMPILER_WARNINGS})

add_executable(stream main.cpp)
target_compile_features(stream PRIVATE cxx_std_17)

add_executable(stream_test tests/stream_tests.cpp)
target_link_libraries(stream_test test_runner)
target_compile_features(stream_test PRIVATE cxx_std_17)

add_test(stream_test stream_test)
