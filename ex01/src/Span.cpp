#include "Span.hpp"
#include <algorithm>

using std::vector;

Span::Span() {}

Span::Span(const unsigned int& size) { _array.reserve(size); }

Span::Span(const Span& toCopy) : _array(toCopy._array) {}

Span::~Span() {}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		vector<int> tmp(other._array.begin(), other._array.end());
		_array.swap(tmp);
	}

	return (*this);
}

int& Span::operator[](unsigned int index)
{
	if (index >= _array.size())
		throw std::out_of_range("Index out of range");

	return (_array[index]);
}

const int& Span::operator[](unsigned int index) const
{
	if (index >= _array.size())
		throw std::out_of_range("Index out of range");

	return (_array[index]);
}

void Span::addNumber(const int& value)
{
	if (_array.size() >= _array.capacity())
		throw std::overflow_error("Span is full");

	_array.push_back(value);
}

long Span::longestSpan() const
{
	if (_array.size() < 2)
		throw std::length_error("Span is empty");

	int min = *std::min_element(_array.begin(), _array.end());
	int max = *std::max_element(_array.begin(), _array.end());

	return (max - min);
}

long Span::shortestSpan() const
{
	if (_array.size() < 2)
		throw std::length_error("Span is empty");

	vector<int> tmp(_array);
	std::sort(tmp.begin(), tmp.end());

	long span = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
		span = (tmp[i] - tmp[i - 1]) < span ? tmp[i] - tmp[i - 1] : span;
	
	return (span);
}
