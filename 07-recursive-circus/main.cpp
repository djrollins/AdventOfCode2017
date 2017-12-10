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

using program_cache = std::map<std::string, program>;
using weight_cache = std::map<std::string, int>;

static int total_weight(
		program const &program,
		program_cache const &programs,
		weight_cache &weights)
{
	if (auto found = weights.find(program.name); found != std::end(weights))
		return found->second;

	auto &weight = weights[program.name];

	weight = std::accumulate(
			std::begin(program.children), std::end(program.children), program.weight,
			[&ps=programs, &ws=weights](auto w, auto const &n) {
				return w + total_weight(ps.at(n), ps, ws);
			});

	return weight;
}

int main()
{
	std::regex regex{R"(\w+)"};

	std::string buffer;
	std::vector<std::string> vec;

	program_cache programs;
	std::set<std::string> left;
	std::set<std::string> right;

	while (std::getline(std::cin, buffer)) {
		if (!buffer.size()) continue;

		std::copy(
			std::sregex_token_iterator(buffer.begin(), buffer.end(), regex, 0),
			std::sregex_token_iterator(),
			std::back_inserter(vec));

		program prog{vec[0], std::atoi(vec[1].c_str()), {vec.begin() + 2, vec.end()}};
		auto [iter, _] = programs.emplace(vec[0], std::move(prog));

		left.insert(iter->first);
		right.insert(std::begin(iter->second.children), std::end(iter->second.children));

		vec.clear();
	}

	std::string root;

	// ptr to root as I know ther is only one.
	std::set_difference(left.begin(), left.end(), right.begin(), right.end(), &root);

	std::cout << "root: " << root << '\n';

	weight_cache weights;
	auto unbalanced = std::find_if(std::begin(programs), std::end(programs),
			[&programs, &weights](auto const &entry) {
				auto const &kids = entry.second.children;
				return !std::equal(std::begin(kids), std::end(kids), std::rbegin(kids),
					[&ps=programs, &ws=weights](auto const &lhs, auto const &rhs) {
						return total_weight(ps.at(lhs), ps, ws)
							== total_weight(ps.at(rhs), ps, ws);
					});
			});

	std::cout << "unbalanced: " << unbalanced->first << '\n';
	std::cout << "children: " << '\n';
	for (auto const &child_name : unbalanced->second.children) {
		auto const &child = programs.at(child_name);
		std::cout << '\t' << child.name << ": (" << child.weight << ") "
			<< total_weight(child, programs, weights) << '\n';

	}
}
