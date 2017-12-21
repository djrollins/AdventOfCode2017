#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

template<typename Iter>
class cyclic_iterator
{
	Iter first_;
	Iter current_;
	Iter last_;
public:
	using value_type = typename std::iterator_traits<Iter>::value_type;
	using difference_type = typename std::iterator_traits<Iter>::difference_type;
	using reference = typename std::iterator_traits<Iter>::reference;
	using pointer = typename std::iterator_traits<Iter>::pointer;
	using iterator_category = std::input_iterator_tag;

	cyclic_iterator(Iter first, Iter last) :
		first_(first), current_(first), last_(last) {}

	cyclic_iterator operator++()
	{
		auto cpy = *this;
		advance();
		return cpy;
	}

	cyclic_iterator &operator++(int)
	{
		advance();
		return *this;
	}

	reference operator*()
	{
		return *current_;
	}

	bool operator==(cyclic_iterator const &rhs)
	{
		return current_ == rhs.current_;
	}

	bool operator!=(cyclic_iterator const &rhs)
	{
		return !(*this == rhs);
	}
private:
	void advance()
	{
		++current_;
		if (current_ == last_) current_ = first_;
	}
};

static std::vector<uint8_t> generate_sequence(std::size_t const count)
{
	std::vector<uint8_t> seq(count);
	std::iota(std::begin(seq), std::end(seq), 0);
	return seq;
}

template<typename CyclicIter, typename LengthsIter>
int run_hash(CyclicIter &cycle, LengthsIter begin, LengthsIter end, int skip = 0)
{
	std::vector<uint8_t> tmp(256);

	for (auto iter = begin; iter != end; ++iter) {
		auto end = std::copy_n(cycle, *iter, std::begin(tmp));
		std::reverse(std::begin(tmp), end);
		cycle = std::next(std::copy(std::begin(tmp), end, cycle), skip++);
	}

	return skip;
}

void part1()
{
	auto seq = generate_sequence(256);

	std::vector<uint8_t> lengths{130,126,1,11,140,2,255,207,18,254,246,164,29,104,0,224};

	cyclic_iterator<decltype(seq)::iterator> iter(std::begin(seq), std::end(seq));

	run_hash(iter, std::begin(lengths), std::end(lengths));

	std::cout << seq[0] * seq[1] << '\n';
}

void part2()
{
	auto seq = generate_sequence(256);

	std::string input{"130,126,1,11,140,2,255,207,18,254,246,164,29,104,0,224"};
	const uint8_t extra_lengths[] = {17, 31, 73, 47, 23};

	std::vector<uint8_t> lengths;
	std::copy(std::begin(input), std::end(input), std::back_inserter(lengths));
	std::copy(std::begin(extra_lengths), std::end(extra_lengths), std::back_inserter(lengths));

	cyclic_iterator<decltype(seq)::iterator> iter(std::begin(seq), std::end(seq));

	auto skip = 0;
	for (int i = 0; i < 64; ++i)
		skip = run_hash(iter, std::begin(lengths), std::end(lengths), skip);

	auto reducer = std::begin(seq);
	auto end = std::end(seq);

	while (reducer != end) {
		std::cout << std::hex << std::setfill('0') << std::setw(2)
			<< static_cast<int>(std::accumulate(reducer, reducer + 16, 0, std::bit_xor{}));
		reducer += 16;
	}
}

int main()
{
	part1();
	part2();
}
