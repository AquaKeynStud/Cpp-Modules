#include <climits>
#include <cstdlib>
#include "ScalarConverter.hpp"

using std::string;

bool isInt(const string& s);
bool isChar(const string& s);
bool isFloat(const string& s);
bool isDouble(const string& s);

void ScalarConverter::convert(const string& literal)
{
	double value;

	if (isChar(literal))
		value = <static_cast>()
}

/* -- Utility Functions -- */

bool isChar(const string& s)
{
	return (s.length() == 1 and not isdigit(s[0]));
}

bool isInt(const string& s)
{
	char *end;
	long value = strtol(s.c_str(), &end, 10);

	return (not (s.empty() or *end or value > INT_MAX or value < INT_MIN));
}

bool isFloat(const string& s)
{
	if (s == "nanf" or s == "+inff" or s == "-inff")
		return (true);

	char *end;
	strtof(s.c_str(), &end);
	return (*end == 'f' and *++end == '\0');
}

bool isDouble(const string& s)
{
	if (s == "nan" || s == "+inf" || s == "-inf")
		return (true);

	char *end;
	strtod(s.c_str(), &end);
	return (*end == '\0');
}
