#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

/* -- Includes -- */

/* -- Class -- */
class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& toCopy);

	~ScalarConverter();

	ScalarConverter& operator=(const ScalarConverter& other);
};

#endif
