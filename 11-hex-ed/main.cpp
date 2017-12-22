#include <algorithm>
#include <numeric>
#include <cmath>
#include <iostream>
#include <regex>
#include <string>
#include <unordered_map>

struct coord
{
	int x = 0;
	int y = 0;
	int z = 0;

	coord &operator+=(const coord &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
		return *this;
	}
};

static const std::unordered_map<std::string, coord> dirs = {
	{"n",  {0, 1, -1}},
	{"ne", {1, 0, -1}},
	{"se", {1, -1, 0}},
	{"s",  {0, -1, 1}},
	{"sw", {-1, 0, 1}},
	{"nw", {-1, 1, 0}}
};


int distance(const coord &from, const coord &to)
{
	using std::abs;
	return (abs(from.x - to.x) + abs(from.y - to.y) + abs(from.z - to.z)) / 2;
}

void move(coord &coord, std::string const &dir)
{
	coord += dirs.at(dir);
}

int main(int argc, char **argv)
{
	(void)argc;

	std::regex splitter{"(ne|se|sw|nw|n|s)"};
	std::string input{argv[1]};
	std::sregex_iterator begin{input.begin(), input.end(), splitter};
	std::sregex_iterator end{};

	std::vector<int> distances;

	std::accumulate(
			begin, end,
			coord{},
			[&distances](auto acc, auto &dir) {
				move(acc, dir.str());
				distances.push_back(distance(coord{}, acc));
				return acc;
			});

	std::cout << "distance: " << distances.back() << '\n';
	std::cout << "furthest: " << *std::max_element(distances.begin(), distances.end()) << '\n';
}
