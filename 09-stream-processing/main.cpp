#include "stream.h"

#include <iostream>
#include <string>

int main()
{
	std::string buffer;

	std::getline(std::cin, buffer);

	auto [score, garbage] = parse(buffer);

	std::cout << "score: " << score << '\n';
	std::cout << "garbage: " << garbage << '\n';
}
