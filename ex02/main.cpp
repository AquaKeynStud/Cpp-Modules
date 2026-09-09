#include <sstream>
#include <climits>
#include <iostream>
#include <stdexcept>
#include "PmergeMe.hpp"

static int	toPositiveInt(const char *str);

int main(int argc, char **argv)
{
	try
	{
		std::vector<int>	input;

		if (argc < 2)
			throw std::runtime_error("Error");

		for (int i = 1; i < argc; ++i)
			input.push_back(toPositiveInt(argv[i]));

		PmergeMe	sorter(input);
		sorter.run();
	} catch (const std::exception& e) {
		std::cerr << e.what() << "\n";
		return (1);
	}

	return (0);
}

static int	toPositiveInt(const char *str)
{
	long				value;
	char				extra;
	std::stringstream	ss(str);

	if (!(ss >> value) || (ss >> extra) || value <= 0 || value > INT_MAX)
		throw std::runtime_error("Error: invalid input");

	return (value);
}
