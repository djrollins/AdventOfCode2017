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

TEST_CASE("part 2: can calculate next highest value")
{
	REQUIRE(266330 == next_highest(265149));
}
