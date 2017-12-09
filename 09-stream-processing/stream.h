#ifndef STREAM_H
#define STREAM_H

#include <cassert>
#include <string_view>

struct parse_result
{
	int score;
	int swallowed;
};

parse_result parse(std::string_view str);

template<typename Iter>
int swallow_garbage(Iter &iter)
{
	int swallowed = 0;
	assert(*iter == '<');
	while (*++iter != '>') {
		if (*iter == '!') ++iter;
		else ++swallowed;
	}

	return swallowed;
}

parse_result parse(std::string_view str)
{
	int garbage = 0;
	int score = 0;
	int level = 0;

	for (auto iter = std::begin(str); iter != std::end(str); ++iter) {
		if (*iter == '{')
			++level;
		else if (*iter == '}')
			score += level--;
		else if (*iter == '<')
			garbage += swallow_garbage(iter);
	}

	return {score, garbage};
}

#endif//STREAM_H
