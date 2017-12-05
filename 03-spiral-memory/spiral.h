#include <cstdlib>

// 37  36  35  34  33  32  31
// 38  17  16  15  14  13  30
// 39  18   5   4   3  12  29
// 40  19   6   1   2  11  28
// 41  20   7   8   9  10  27
// 42  21  22  23  24  25  26
// 43  44  45  46  47  48  49

int manhatten_distance(int n)
{
	if (n == 1)
		return 0;

	int current = 1;
	int distance = 0;
	int direction = -1;
	int x = 0;
	int y = 0;

	while (current < n) {
		distance += 1;
		direction *= -1;

		auto step = distance;
		while (--step && current < n) { ++current; x += direction; };
		step = distance;
		while (--step && current < n) { ++current; y += direction; };
	}

	return std::abs(x) + std::abs(y);
}

