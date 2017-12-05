#include "spiral.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i) {
		auto num = std::atoi(argv[i]);
		std::cout << num << ": " << manhatten_distance(num) << '\n';
	}
}
