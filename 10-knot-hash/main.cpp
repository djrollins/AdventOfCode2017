#include <algorithm>
#include <cstdint>
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

static std::vector<int> generate_sequence(std::size_t const count)
{
	std::vector<int> seq(count);
	std::iota(std::begin(seq), std::end(seq), 0);
	return seq;
}

int main()
{
	std::size_t const count = 256;
	auto seq = generate_sequence(count);

	std::vector<int> lengths{130,126,1,11,140,2,255,207,18,254,246,164,29,104,0,224};

	cyclic_iterator<decltype(lengths)::iterator> iter(std::begin(seq), std::end(seq));

	auto skip = 0;
	std::vector<int> tmp(count);

	for (auto length : lengths) {
		auto end = std::copy_n(iter, length, std::begin(tmp));
		std::reverse(std::begin(tmp), end);
		iter = std::next(std::copy(std::begin(tmp), end, iter), skip++);
	}

	std::cout << seq[0] * seq[1] << '\n';
}
