add_compile_options(${COMPILER_WARNINGS})

add_executable(passphrases main.cpp)
target_compile_features(passphrases PRIVATE cxx_std_17)
