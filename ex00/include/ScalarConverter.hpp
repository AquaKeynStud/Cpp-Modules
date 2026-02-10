#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

/* -- Includes -- */
#include <string>

/* -- Class -- */
class ScalarConverter
{
public:
	static void	convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);

	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter&);
};

#endif
