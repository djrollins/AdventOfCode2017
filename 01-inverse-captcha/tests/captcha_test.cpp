#include "../captcha.h"
#include "catch.hpp"

#include <numeric>
#include <vector>

TEST_CASE("1122 = 3") { REQUIRE(3 == captcha("1122")); }

TEST_CASE("1111 = 4") { REQUIRE(4 == captcha("1111")); }

TEST_CASE("91212129 = 9") { REQUIRE(9 == captcha("91212129")); }
