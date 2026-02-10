#include <string>
#include <climits>
#include <cstdlib>
#include <iostream>
#include "Type_utils.hpp"

using std::cout;
using std::string;

/* ╭━━━━━━━━━━━━══════════╕ ❖ CAST PRINTERS ❖ ╒═══════════━━━━━━━━━━━━╮ */

void printInt(const double& n)
{
	if (n < INT_MIN or n > INT_MAX)
		cout << RED "Impossible 🈲";
	else
		cout << GREEN << static_cast<int>(n);
}

void printChar(const double& n)
{
	char c = static_cast<char>(n);

	if (n < 0 or n > 127)
		cout << RED "Impossible 🈲";
	else if (!isprint(c))
		cout << RED "Non displayable 📛";
	else
		cout << GREEN "'" << c << "'";
}

void printFloat(const double& n)
{
	if (isInf(n))
	{
		cout << YELLOW << (n < 0 ? "-inff" : "+inff");
		return ;
	}

	float f = static_cast<float>(n);

	cout << GREEN << f << (f == static_cast<int>(n) ? ".0f" : "f");
}

void printDouble(const double& n)
{
	if (isInf(n))
	{
		cout << YELLOW << (n < 0 ? "-inf" : "+inf");
		return ;
	}

	cout << GREEN << n << (n == static_cast<int>(n) ? ".0" : "");
}

/* ╭━━━━━━━━━━━━══════════╕ ❖ TYPE CHECKERS ❖ ╒═══════════━━━━━━━━━━━━╮ */

bool isNumber(const string& s)
{
	return (isInt(s) or isFloat(s) or isDouble(s));
}

bool isNan(const double& n) { return (n != n); }

bool isInf(const double& n) { return ((n == 1.0 / 0.0) or (n == -1.0 / 0.0)); }

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
