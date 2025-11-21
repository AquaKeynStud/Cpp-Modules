#ifndef WEAPON_HPP
# define WEAPON_HPP

/* -- Includes -- */
#include <string>

/* -- Class -- */
class Weapon
{
private:
	std::string	type;

public:
	Weapon( const std::string& type );
	~Weapon();

	// Getters //
	const std::string&	getType( void );

	// Setters //
	void	setType( const std::string& type );
};

#endif