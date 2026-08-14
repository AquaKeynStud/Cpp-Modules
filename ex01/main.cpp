#include "RPN.hpp"

using std::cerr;

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cerr << "Format: ./RPN <expression>\n";
		return (1);
	}

	try {
		handle_expression(av[1]);
	} catch (const std::exception& e) {
		cerr << "Error\n";
	}

	return (0);
}
