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

	int x, y;

	switch (difference_in_whole_sides) {
		case 0:
			x = corner - remainder;
			y = -corner;
			break;
		case 1:
			x = -corner;
			y = -corner + remainder;
			break;
		case 2:
			x = -corner + remainder;
			y = corner;
			break;
		case 3:
			x = corner;
			y = corner - remainder;
			break;
	}

	return std::abs(x) + std::abs(y);
}

