add_compile_options(${COMPILER_WARNINGS})

add_executable(captcha main.cpp captcha.cpp)
target_compile_features(captcha PRIVATE cxx_std_17)

add_executable(captcha_test tests/captcha_test.cpp captcha.cpp)
target_link_libraries(captcha_test test_runner)
target_compile_features(captcha_test PRIVATE cxx_std_17)

add_test(captcha_test captcha_test)
