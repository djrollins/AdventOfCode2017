add_compile_options(${COMPILER_WARNINGS})

add_executable(jumps main.cpp)
target_compile_features(jumps PRIVATE cxx_std_17)
