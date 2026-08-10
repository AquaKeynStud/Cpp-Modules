#include "BitcoinExchange.hpp"

using std::map;
using std::cout;
using std::string;

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Error: could not open file\n";
		return (1);
	}

	map<string, double>	database;
	if (!fill_database(database))
		return (1);
	
	process_input(av[1], database);

	return (0);
}
