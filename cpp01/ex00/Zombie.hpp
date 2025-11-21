#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

/* -- Includes -- */
#include <string>

/* -- Classes -- */
class Zombie
{

private:
	std::string	name;

public:
	Zombie();
	Zombie( std::string const &given_name );
	~Zombie();

	void	announce( void );

};

/* -- Other Functions -- */
Zombie* newZombie( std::string name );
void	randomChump( std::string name );

#endif
