#include <cstdlib>
#include <iostream>
#include "Type_utils.hpp"
#include "ScalarConverter.hpp"

using std::cout;
using std::string;

void ScalarConverter::convert(const string& literal)
{
	double value = 0.0;
	bool error = not isNumber(literal);
	static const string types[4] = {"✒️ Char: ", "🎐 Int: ", "🍡 Float: ", "🍣 Double: "};

	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else if (not error)
		value = strtod(literal.c_str(), NULL);

	for (int i = 0; i < 4; i++)
	{
		cout << BOLD << types[i];

		if (!isChar(literal) and (error or isNan(value)))
			cout << ((i < 2) ? RED "Impossible 🈲" : (i == 2) ? PURPLE "nanf" : PURPLE "nan");
		else if (i == 0)
			printChar(value);
		else if (i == 1)
			printInt(value);
		else if (i == 2)
			printFloat(value);
		else
			printDouble(value);

		cout << RESET;
	}
}
