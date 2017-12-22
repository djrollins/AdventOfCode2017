add_compile_options(${COMPILER_WARNINGS})

add_executable(hexed main.cpp)
target_compile_features(hexed PRIVATE cxx_std_17)
