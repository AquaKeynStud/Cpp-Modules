#include "Harl.hpp"
#include <iostream>

int main( int argc, char **argv )
{
	Harl	harl;

	if (argc < 2)
		std::cout << "\e[31;1m🈲 Error: Please provide an argument. 🈲\e[0m" << std::endl;

	argv++;
	while (*argv)
		harl.complain(*argv++);
	
	return (0);
}