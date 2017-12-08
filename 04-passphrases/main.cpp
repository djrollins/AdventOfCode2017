#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using word_iter = std::istream_iterator<std::string>;

int main()
{
	int count_unique = 0;
	int count_anagram = 0;

	std::string buffer;

	while(std::getline(std::cin, buffer)) {
		if (!buffer.size()) continue;

		std::stringstream stream{buffer};

		std::vector<std::string> words;
		std::set<std::string> unique_words;
		std::set<std::string> unique_anagrams;

		std::copy(word_iter(stream), word_iter(), std::back_inserter(words));
		std::copy(words.begin(), words.end(), std::inserter(unique_words, unique_words.end()));
		std::transform(
			words.begin(), words.end(),
			std::inserter(unique_anagrams, unique_anagrams.end()),
			[](auto str){ std::sort(str.begin(), str.end()); return str; });

		if (words.size() == unique_words.size()) ++count_unique;
		if (words.size() == unique_anagrams.size()) ++count_anagram;
	}

	std::cout << count_unique << '\n';
	std::cout << count_anagram << '\n';
}
