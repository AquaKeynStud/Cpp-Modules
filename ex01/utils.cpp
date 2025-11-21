#include "utils.hpp"

void wrapGetline(std::string &s)
{
	if (!std::getline(std::cin, s))
	{
		if (std::cin.eof())
			std::cout << "\n\e[33;1m☣️  Input error (EOF). Aborting. ☣️ \e[0m\n";
		else
			std::cout << "\n\e[33;1m☣️  Read error (getline). Aborting. ☣️ \e[0m\n";
		std::exit(1);
	}
}

bool isPhone(std::string &s)
{
	for (std::string::size_type i = 0; i < s.size(); i++)
	{
		if (i == 0 && s[i] == '+')
			continue;
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	}
	return (true);
}

void valuePadding(const std::string &value)
{
	if (value.size() <= 10)
		std::cout << std::string(10 - value.size(), ' ') + value + "|";
	else
		std::cout << value.substr(0, 9) + ".|";
}

int toInt(std::string &s)
{
	int					result;
	std::stringstream	tmp(s);

	tmp >> result;
	if (tmp.fail())
		return (-1);
	return (result);
}
