#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>

template<typename BeginIter, typename EndIter>
void reallocate(BeginIter first, EndIter last)
{
	auto bank = std::max_element(first, last);
	auto blocks = *bank;
	*bank = 0;

	while(blocks--) {
		++bank;
		if (bank == last) bank = first;
		++(*bank);
	}
}

int main(int argc, char *argv[])
{
	std::vector<int> banks;
	std::transform(argv + 1, argv + argc, std::back_inserter(banks), std::atoi);
	std::vector<std::vector<int>> history{banks};

	int count = 0;
	int cycles = 0;

	for (bool uniq = true; uniq; ++count) {
		reallocate(banks.begin(), banks.end());
		assert(old_banks != bank);
		auto found = std::find(history.cbegin(), history.cend(), banks);
		cycles = history.end() - found;
		uniq = found == history.end();
		history.push_back(banks);
	}

	std::cout << count << '\n';
	std::cout << cycles << '\n';
}
