#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <stdexcept>

class	Span
{
public:
	Span();
	Span(const unsigned int& size);
	Span(const Span& toCopy);

	~Span();

	Span&		operator=(const Span& other);
	int&		operator[](unsigned int index);
	const int&	operator[](unsigned int index) const;

	long		longestSpan(void) const;
	long		shortestSpan(void) const;

	void	addNumber(const int& n);

	template <typename Iterator>
	void	addNumbers(Iterator begin, Iterator end)
	{
		if (_array.size() + std::distance(begin, end) > _array.capacity())
			throw std::overflow_error("Not enough space in span");
		
		_array.insert(_array.end(), begin, end);
	}

private:
	std::vector<int>	_array;
};

#endif
