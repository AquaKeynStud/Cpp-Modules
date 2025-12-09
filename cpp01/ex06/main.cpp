#include "Harl.hpp"
#include <iostream>

int main( int argc, char **argv )
{
	Harl	harl;

	if (argc < 2)
		std::cout << "Please provide an argument." << std::endl;

	argv++;
	while (*argv)
		harl.complain(*argv++);
	
	return (0);
}