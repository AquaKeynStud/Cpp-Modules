#ifndef HARL_HPP
# define HARL_HPP

/* -- Includes -- */
#include <string>

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