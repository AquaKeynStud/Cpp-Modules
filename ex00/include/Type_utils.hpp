#ifndef TYPE_UTILS_HPP
# define TYPE_UTILS_HPP

/* -- Includes -- */
#include <string>

/* -- Colors -- */
#define	BOLD	"\e[1m"
#define RESET	"\e[0m\n"

#define	RED		"\e[1;31m"
#define	GREEN	"\e[1;32m"
#define	YELLOW	"\e[1;33m"
#define PURPLE	"\e[1;35m"


/* -- Cast Printers -- */
void	printInt(const double&);
void	printChar(const double&);
void	printFloat(const double&);
void	printDouble(const double&);

/* -- Type Checkers -- */
bool	isInt(const std::string&);
bool	isChar(const std::string&);
bool	isFloat(const std::string&);
bool	isDouble(const std::string&);
bool	isNumber(const std::string&);

bool	isNan(const double&);
bool	isInf(const double&);

#endif
