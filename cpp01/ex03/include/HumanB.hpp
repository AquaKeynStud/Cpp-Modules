#ifndef HUMANB_HPP
# define HUMANB_HPP

/* -- Includes -- */
#include "Weapon.hpp"

/* -- Class -- */
class HumanB
{
private:
	const std::string	_name;
	Weapon*				_weapon;

public:
	HumanB( const std::string& name );
	~HumanB();

	// Setters //
	void	setWeapon( Weapon& weapon );

	void	attack( void ) const;
};

#endif