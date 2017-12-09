add_compile_options(${COMPILER_WARNINGS})

add_executable(registers main.cpp)
target_compile_features(registers PRIVATE cxx_std_17)
