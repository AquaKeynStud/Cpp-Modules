#include "Harl.hpp"
#include <iostream>

int main( int argc, char **argv )
{
	Harl	harl;
	int		i = 1;

	if (argc < 2)
		std::cout << "\e[31;1m🈲 Error: Please provide an argument. 🈲\e[0m" << std::endl;

	while (argv[i])
		harl.complain(argv[i++]);

	return (0);
}