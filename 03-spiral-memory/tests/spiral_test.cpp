#include "../spiral.h"
#include "catch.hpp"

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

TEST_CASE("can find manhatten distance for position 1024")
{
	REQUIRE(31 == manhatten_distance(1024));
}

