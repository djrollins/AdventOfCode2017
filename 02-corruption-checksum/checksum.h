#ifndef CHECKSUM_H
#define CHECKSUM_H

#include <numeric>
#include <vector>
#include <string>

std::vector<int> parse_row(const std::string &str);

int minmax_diff(const std::vector<int> &row);
int find_divisor(std::vector<int> row);

template<typename RowFunc>
int checksum(const std::vector<std::vector<int>> &sheet, RowFunc func)
{
	return std::accumulate(
		std::cbegin(sheet), std::cend(sheet), 0,
		[&func](auto acc, auto row) {
			return acc + func(row);
		});
}

#endif//CHECKSUM_H
