#include <cassert>
#include <iostream>
#include <limits>
#include <regex>
#include <string>
#include <map>

using comparitor = std::function<bool(int, int)>;

const std::map<std::string, comparitor> ops{
	{"==", std::equal_to<int>{}},
	{"!=", std::not_equal_to<int>{}},
	{"<" , std::less<int>{}},
	{">" , std::greater<int>{}},
	{"<=", std::less_equal<int>{}},
	{">=", std::greater_equal<int>{}}
};

using registers = std::map<std::string, int, std::less<>>;
using str = std::string const &;

static int max_val = std::numeric_limits<int>::min();

static void eval(registers &regs, str target_reg, str target_cmd, int target_val,
		str cond_reg, str cond_op, int cond_val)
{
	auto &target = regs[target_reg];

	if (ops.at(cond_op)(regs[cond_reg], cond_val)) {
		if (target_cmd == "inc") {
			target += target_val;
		} else {
			target -= target_val;
		}
	}

	if (target > max_val)
		max_val = target;
}

int main()
{
	registers regs;

	std::regex regex{R"((\w+) (dec|inc) (-?\d+) if (\w+) ([<=!>]+) (-?\d+))"};

	std::string buffer;
	std::smatch match;

	while (std::getline(std::cin, buffer)) {
		bool is_match = std::regex_match(buffer.cbegin(), buffer.cend(), match, regex);
		assert(is_match);

		auto const target_reg = match[1].str();
		auto const target_cmd = match[2].str();
		auto const target_val = match[3].str();
		auto const cond_reg = match[4].str();
		auto const cond_op = match[5].str();
		auto const cond_val = match[6].str();

		eval(regs, target_reg, target_cmd, std::atoi(target_val.c_str()), cond_reg, cond_op, std::atoi(cond_val.c_str()));
	}

	auto max = std::max_element(std::begin(regs), std::end(regs),
		[](auto const &lhs, auto const &rhs) {
			return lhs.second < rhs.second;
		});

	assert(max != std::end(regs));

	std::cout << "max at end: " << max->second << '\n';
	std::cout << "max ever:   " << max_val << '\n';
}
