#include "catch.hpp"
#include "../stream.h"

TEST_CASE("it can recognise garbage")
{
	std::string str{"<>"};
	auto iter = std::cbegin(str);
	auto swallowed = swallow_garbage(iter);
	REQUIRE(iter == std::end(str) -1);
	REQUIRE(0 == swallowed);

	str = "<random characters>";
	iter = std::cbegin(str);
	swallowed = swallow_garbage(iter);
	REQUIRE(iter == std::end(str) - 1);
	REQUIRE(17 == swallowed);

	str = "<<<<>";
	iter = std::cbegin(str);
	swallowed = swallow_garbage(iter);
	REQUIRE(iter == std::end(str) - 1);
	REQUIRE(3 == swallowed);

	str = "<{!>}>";
	iter = std::cbegin(str);
	swallowed = swallow_garbage(iter);
	REQUIRE(iter == std::end(str) - 1);
	REQUIRE(2 == swallowed);

	str = "<!!>";
	iter = std::cbegin(str);
	swallowed = swallow_garbage(iter);
	REQUIRE(iter == std::end(str) - 1);
	REQUIRE(0 == swallowed);

	str = "<!!!>>";
	iter = std::cbegin(str);
	swallowed = swallow_garbage(iter);
	REQUIRE(iter == std::end(str) - 1);
	REQUIRE(0 == swallowed);

	str = "<{o\"i!a,<{i<a>";
	iter = std::cbegin(str);
	swallowed = swallow_garbage(iter);
	REQUIRE(iter == std::end(str) - 1);
	REQUIRE(10 == swallowed);
}

TEST_CASE("it can count total groups")
{
	REQUIRE(1 == parse("{}").score);
	REQUIRE(6 == parse("{{{}}}").score);
	REQUIRE(5 == parse("{{},{}}").score);
	REQUIRE(16 == parse("{{{},{},{{}}}}").score);
	REQUIRE(16 == parse("{{{},{},{{}}}}").score);
	REQUIRE(1 == parse("{<a>,<a>,<a>,<a>}").score);
	REQUIRE(9 == parse("{{<ab>},{<ab>},{<ab>},{<ab>}}").score);
	REQUIRE(9 == parse("{{<!!>},{<!!>},{<!!>},{<!!>}}").score);
	REQUIRE(3 == parse("{{<a!>},{<a!>},{<a!>},{<ab>}}").score);
}
