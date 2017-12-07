#include "../spiral.h"
#include "catch.hpp"

// 37  36  35  34  33  32  31
// 38  17  16  15  14  13  30
// 39  18   5   4   3  12  29
// 40  19   6   1   2  11  28
// 41  20   7   8   9  10  27
// 42  21  22  23  24  25  26
// 43  44  45  46  47  48  49

TEST_CASE("can find relative coordinate for position 1")
{
	REQUIRE(0 == manhatten_distance(1));
}

TEST_CASE("can find manhatten distance for position 12")
{
	REQUIRE(3 == manhatten_distance(12));
}

TEST_CASE("can find manhatten distance for position 23")
{
	REQUIRE(2 == manhatten_distance(23));
}

TEST_CASE("can find manhatten distance for position 24")
{
	REQUIRE(3 == manhatten_distance(24));
}

TEST_CASE("can find manhatten distance for position 25")
{
	REQUIRE(4 == manhatten_distance(25));
}

TEST_CASE("can find manhatten distance for position 26")
{
	REQUIRE(5 == manhatten_distance(26));
}

TEST_CASE("can find manhatten distance for position 1024")
{
	REQUIRE(31 == manhatten_distance(1024));
}

#include <map>
#include <iostream>

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
		if (section_len-- > side_len)
			next.first += direction;
		else 
			next.second += direction;

		if (section_len == 0) {
			direction *= -1;
			side_len += 1;
			section_len = side_len * 2;
		}

		return next;
	}
};

TEST_CASE("dooot")
{
	coord_generator gen;

	const int val = 265149;
	const int size = std::ceil(std::pow(val, 1.0/5.0));
	const int max_size = size % 2 == 0 ? size : size + 1;
	const int centre = max_size / 2;

	std::vector<std::vector<int>> grid(max_size);
	for (auto &row : grid) row.resize(max_size, 0);
	grid[centre][centre] = 1;

	auto calculate_coord = [&grid, &centre](auto coord) {
		const std::pair<int, int> neighbours[] = {
			{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

		int sum = 0;

		for (auto &neighbour : neighbours) {
			sum += grid[coord.first + neighbour.first + centre][coord.second + neighbour.second + centre];
		}

		grid[coord.first + centre][coord.second + centre] = sum;

		return sum;
	};

	int highest = 0;
	while (highest <= val) {
		highest = calculate_coord(gen());
	}

	REQUIRE(0 == highest);
}
