#include "../checksum.h"
#include "catch.hpp"

#include <string>
#include <vector>

TEST_CASE("can parse space delimted digits into vector")
{
	std::string str{"5 1 9 5"};

	std::vector<int> row{5, 1, 9, 5};

	REQUIRE(row == parse_row(str));
}

TEST_CASE("it can find the result of perfect division")
{
	std::vector<int> row{5, 9, 2, 8};

	REQUIRE(4 == find_divisor(row));
}

TEST_CASE("it can find minmax difference")
{
	std::vector<int> row{5, 1, 9, 5};

	REQUIRE(8 == minmax_diff(row));
}
