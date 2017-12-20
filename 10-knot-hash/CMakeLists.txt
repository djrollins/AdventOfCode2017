add_compile_options(${COMPILER_WARNINGS})

add_executable(knothash main.cpp)
target_compile_features(knothash PRIVATE cxx_std_17)
