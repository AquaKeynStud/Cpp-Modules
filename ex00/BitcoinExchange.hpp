#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>

bool	check_date_format(const std::string& date);
bool	fill_database(std::map<std::string, double>& db);
void	process_input(const std::string& filename, const std::map<std::string, double>& db);

#endif
