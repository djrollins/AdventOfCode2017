#include "../captcha.h"
#include "catch.hpp"

#include <numeric>
#include <vector>

TEST_CASE("captcha_adjacent(1122) = 3") { REQUIRE(3 == captcha_adjacent("1122")); }

TEST_CASE("catpcha_adjacent(1111) = 4") { REQUIRE(4 == captcha_adjacent("1111")); }

TEST_CASE("captcha_adjacent(91212129) = 9") { REQUIRE(9 == captcha_adjacent("91212129")); }

TEST_CASE("captcha_midpoint(1212) = 6") { REQUIRE(6 == captcha_midpoint("1212")); }

TEST_CASE("captcha_midpoint(1221) = 0") { REQUIRE(0 == captcha_midpoint("1221")); }

TEST_CASE("captcha_midpoint(123425) = 4") { REQUIRE(4 == captcha_midpoint("123425")); }

TEST_CASE("captcha_midpoint(123123) = 12") { REQUIRE(12 == captcha_midpoint("123123")); }

TEST_CASE("captcha_midpoint(12131415) = 4") { REQUIRE(4 == captcha_midpoint("12131415")); }
