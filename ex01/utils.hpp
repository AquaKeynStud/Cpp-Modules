#ifndef UTILS_HPP
# define UTILS_HPP

/* -- Includes -- */
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

/* -- Functions -- */
int		toInt(std::string &s);
bool	isPhone(std::string &s);
void	wrapGetline(std::string &s);
void	valuePadding(const std::string &value);


#endif