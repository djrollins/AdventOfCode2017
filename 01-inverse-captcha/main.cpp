#include "captcha.h"

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[])
{
	std::vector<std::string> args(argv + 1, argv + argc);

	for (const auto &arg : args) {
		std::cout << "adjacent: " << captcha_adjacent(arg) << '\n';
		std::cout << "midpoint: " << captcha_midpoint(arg) << '\n';
	}
}
