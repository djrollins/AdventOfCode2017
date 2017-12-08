#ifndef CAPTCHA_H
#define CAPTCHA_H

#include <string_view>

int captcha_adjacent(std::string_view str);
int captcha_midpoint(std::string_view str);

#endif//CAPTCHA_H
