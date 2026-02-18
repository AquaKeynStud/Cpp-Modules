#include <iostream>
#include <typeinfo>
#include <stdexcept>

typedef	unsigned int uint;

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(const Array<T>& toCopy) : _data(NULL), _size(toCopy._size)
{
	if (_size)
	{
		_data = new T[_size]();
		for (uint i = 0; i < _size; i++)
			_data[i] = toCopy._data[i];
	}
}

template <typename T>
Array<T>::Array(const uint size) : _data(new T[size]()), _size(size) {}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array of type <" << getTypeName<T>() << "> destroyed." << std::endl;
	delete[] _data;
}

template <typename T>
T& Array<T>::operator[](uint i)
{
	if (i >= _size)
		throw std::out_of_range("Index out of bounds");
	
	return (_data[i]);
}

template <typename T>
const T& Array<T>::operator[](uint i) const
{
	if (i >= _size)
		throw std::out_of_range("Index out of bounds");
	
	return (_data[i]);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this == &other)
		return (*this);

	delete[] _data;

	_size = other._size;
	_data = new T[_size]();

	for (uint i = 0; i < _size; i++)
		_data[i] = other._data[i];

	return (*this);
}

template <typename T>
uint Array<T>::size() const { return (_size); }
