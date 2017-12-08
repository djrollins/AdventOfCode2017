add_compile_options(${COMPILER_WARNINGS})

add_executable(allocations main.cpp)
target_compile_features(allocations PRIVATE cxx_std_17)
