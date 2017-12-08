#include "spiral.h"

#include <cmath>

static int side_length(int n)
{
	int root = static_cast<int>(std::ceil(std::sqrt(n)));
	return root % 2 ? root : root + 1;
}

int manhatten_distance(int n)
{
	if (n == 1)
		return 0;

	int side = side_length(n);
	int current = static_cast<int>(std::pow(side, 2));
	int difference = current - n;
	int remainder = difference % (side - 1);
	int corner = side / 2;

	return std::abs(corner - remainder) + corner;
}
