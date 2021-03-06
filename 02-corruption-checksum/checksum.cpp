#include "checksum.h"

#include <algorithm>
#include <numeric>
#include <iterator>
#include <sstream>

int minmax_diff(const std::vector<int> &row)
{
	auto [min, max] = minmax_element(std::cbegin(row), std::cend(row));
	return *max - *min;
}

int find_divisor(std::vector<int> row)
{
	auto first = std::begin(row);
	auto last = std::end(row);

	std::sort(first, last, std::greater<>{});

	for (; first != last - 1; ++first) {
		auto curr = std::find_if(first + 1, last, [num=*first](auto denom) { return num % denom == 0; });
		if (curr != last) return *first / *curr;
	}

	return 0;
}

std::vector<int> parse_row(const std::string &str)
{
	std::vector<int> row;
	std::istringstream ss{str};
	std::copy(std::istream_iterator<int>{ss}, std::istream_iterator<int>{}, std::back_inserter(row));
	return row;
}
