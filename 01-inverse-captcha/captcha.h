#include <numeric>
#include <string_view>

// Precondition: str only contains characters '0'-'9'
int captcha(std::string_view str) {
	const auto begin = std::begin(str);
	const auto end = std::end(str);

	const auto to_digit = [](char c){ return c - '0'; };

	if (begin == end)
		return 0;

	return std::inner_product(
			begin + 1, end, begin,
			*begin == *(end - 1) ? to_digit(*begin) : 0,
			[](const int &a, const int &b) { return a + b; },
			[&to_digit](const char &a, const char &b) { return b == a ? to_digit(b) : 0; });
}
