#include <cmath>
#include <cstdlib>

int side_length(int n)
{
	int root = std::ceil(std::sqrt(n));
	return root % 2 ? root : root + 1;
}

int manhatten_distance(int n)
{
	if (n == 1)
		return 0;

	int side = side_length(n);
	int current = std::pow(side, 2);
	int direction = 1;
	int x = side / 2;
	int y = -(side / 2);

	while (current > n) {
		auto step = side - 1;
		while (step-- && current > n) { --current; x -= direction; };
		step = side - 1;
		while (step-- && current > n) { --current; y += direction; };

		direction *= -1;
	}

	return std::abs(x) + std::abs(y);
}

