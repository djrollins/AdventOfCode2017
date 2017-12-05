#include <numeric>
#include <string>
#include <string_view>

template<typename InputIt1, typename InputIt2, typename InputIt3>
int captcha(InputIt1 first1, InputIt2 last1, InputIt3 first2)
{
	const auto to_digit = [](char c){ return c - '0'; };

	return std::inner_product(
			first1, last1, first2, 0,
			[](const int &a, const int &b) { return a + b; },
			[&to_digit](const char &a, const char &b) { return b == a ? to_digit(b) : 0; });
}

template<typename InputIt1, typename InputIt2>
int captcha_offset(InputIt1 first, InputIt2 last, int offset)
{
	const auto pivot = std::next(first, offset);

	std::string rotated;
	std::rotate_copy(first, pivot, last, std::back_inserter(rotated));

	return captcha(first, last, std::begin(rotated));
}

int captcha_adjacent(std::string_view str)
{
	return captcha_offset(std::begin(str), std::end(str), 1);
}

int captcha_midpoint(std::string_view str)
{
	const auto first = std::begin(str);
	const auto last = std::end(str);
	const auto offset = std::distance(first, last) / 2;

	return captcha_offset(first, last, offset);
}
