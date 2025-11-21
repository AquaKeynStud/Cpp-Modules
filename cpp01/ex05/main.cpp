#include "Harl.hpp"
#include <iostream>

int main( int argc, char **argv )
{
	Harl	harl;
	int		i = 1;

	(void)argc;
	while (argv[i])
		harl.complain(argv[i++]);
	
	return (0);
}