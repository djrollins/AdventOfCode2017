add_compile_options(${COMPILER_WARNINGS})

add_executable(recursive main.cpp)
target_compile_features(recursive PRIVATE cxx_std_17)
