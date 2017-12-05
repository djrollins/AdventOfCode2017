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
	int difference = current - n;
	int difference_in_whole_sides = difference / (side - 1);
	int remainder = difference % (side - 1);
	int corner = side / 2;

	switch (difference_in_whole_sides) {
		case 0:
			return std::abs(corner - remainder) + std::abs(-corner);
		case 1:
			return std::abs(-corner) + std::abs(-corner + remainder);
		case 2:
			return std::abs(-corner + remainder) + std::abs(corner);
		case 3:
			return std::abs(corner) + std::abs(corner - remainder);
	}

	return 0;
}

