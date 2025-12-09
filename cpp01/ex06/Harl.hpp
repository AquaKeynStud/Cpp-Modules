#ifndef HARL_HPP
# define HARL_HPP

/* -- Includes -- */
#include <string>

/* -- Colors -- */
#define RESET "\e[0m\n"

#define INFO	"\e[38;2;120;180;255;1m"
#define DEBUG	"\e[38;2;255;180;255;1m"
#define WARNING	"\e[38;2;225;225;120;1m"
#define ERROR	"\e[38;2;255;100;100;1m"

/* -- Class -- */
class Harl
{
private:
	void	info( void );
	void	debug( void );
	void	error( void );
	void	warning( void );

public:
	Harl();
	~Harl();

	void	complain( std::string level );
};

#endif