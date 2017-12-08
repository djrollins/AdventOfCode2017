#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
	using int_iter = std::istream_iterator<int>;
	std::vector<int> instructions;

	std::copy(int_iter{std::cin}, int_iter{}, std::back_inserter(instructions));

	auto begin = std::begin(instructions);
	auto end = std::end(instructions);
	auto ptr = begin;

	int jump_count = 0;

	while (ptr >= begin && ptr < end) {
		auto jump = *ptr;
		if (jump >= 3) --*ptr; else ++*ptr;
		ptr += jump;
		++jump_count;
	}

	std::cout << jump_count << '\n';
}
