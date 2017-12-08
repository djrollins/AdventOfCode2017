#include "spiral.h"

#include <algorithm>
#include <cmath>
#include <map>
#include <numeric>
#include <vector>

class coord_generator
{
private:
	int side_len = 1;
	int section_len = side_len * 2;
	int direction = 1;
	std::pair<int, int> next{0, 0};
public:
	std::pair<int, int> operator()()
	{
		auto current = next;

		if (section_len-- > side_len)
			next.first += direction;
		else
			next.second += direction;

		if (section_len == 0) {
			direction *= -1;
			side_len += 1;
			section_len = side_len * 2;
		}

		return current;
	}
};

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

int next_highest(int val)
{
	coord_generator gen;

	std::map<std::pair<int, int>, int> grid{{gen(), 1}};

	auto calculate_coord = [&grid](auto coord) {
		std::pair<int, int> neighbours[] = {
			{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

		auto &sum = grid[coord];

		std::transform(std::begin(neighbours), std::end(neighbours),
				std::begin(neighbours),
				[&coord](auto n) -> std::pair<int, int> {
					return {n.first + coord.first, n.second + coord.second};
				});

		sum = std::accumulate(std::begin(neighbours), std::end(neighbours), 0,
				[&grid](auto acc, auto curr) { return acc + grid[curr]; });

		return sum;
	};

	int highest = 0;
	while (highest <= val) {
		highest = calculate_coord(gen());
	}

	return highest;
}
