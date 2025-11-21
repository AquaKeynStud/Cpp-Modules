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
	Zombie( const std::string& name );
	~Zombie();

	// Setters //
	void	setName( const std::string& name );

	void	announce( void );

};

/* -- Other Functions -- */
Zombie*	zombieHorde( int N, std::string name );

#endif
