#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
private:
	T*				_data;
	unsigned int	_size;

public:
	Array();
	Array(const Array& toCopy);
	Array(const unsigned int n);

	~Array();

	T&			operator[](unsigned int i);
	Array&		operator=(const Array& other);
	const T&	operator[](unsigned int i) const;

	unsigned int	size(void) const;
};

template <typename T>
std::string getTypeName()
{
    std::string pretty = __PRETTY_FUNCTION__;

    std::size_t start = pretty.find("T = ");
    if (start == std::string::npos)
        return ("Unknown");

    start += 4;

    std::size_t end = pretty.find(';', start);
    if (end == std::string::npos)
        end = pretty.find(']', start);

    std::string type = pretty.substr(start, end - start);

    if (type == "std::__cxx11::basic_string<char>")
        return ("std::string");

    return (type);
}

#include "Array.tpp"

#endif
