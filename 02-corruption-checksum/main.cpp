#include "checksum.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::vector<int>> sheet;
	std::string buffer;

	while (std::getline(std::cin, buffer)) {
		sheet.push_back(parse_row(buffer));
	}

	std::cout << "minmax: " << checksum(sheet, minmax_diff) << '\n';
	std::cout << "divisor: " << checksum(sheet, find_divisor) << '\n';
}
