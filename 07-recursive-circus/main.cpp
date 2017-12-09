#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <set>
#include <string>
#include <unordered_map>

struct program
{
	std::string name;
	int weight;
	std::vector<std::string> children;
};

using program_cache = std::unordered_map<std::string, program>;

int main()
{
	std::regex regex{R"(\w+)"};

	std::string buffer;
	std::vector<std::string> vec;

	program_cache programs;
	std::set<std::string_view> left;
	std::set<std::string_view> right;

	while (std::getline(std::cin, buffer)) {
		if (!buffer.size()) continue;
		std::copy(
			std::sregex_token_iterator(buffer.begin(), buffer.end(), regex, 0),
			std::sregex_token_iterator(),
			std::back_inserter(vec));

		program prog{vec[0], std::atoi(vec[1].c_str()), {vec.begin() + 2, vec.end()}};

		auto const [iter, _] = programs.emplace(std::move(vec[0]), std::move(prog));

		auto const &name = iter->first;
		auto const &children = iter->second.children;

		left.insert(name);
		right.insert(std::begin(children), std::end(children));

		vec.clear();
	}


	std::string root;

	// ptr to root as I know ther is only one.
	std::set_difference(left.begin(), left.end(), right.begin(), right.end(), &root);

	std::cout << "root: " << root << '\n';
}
