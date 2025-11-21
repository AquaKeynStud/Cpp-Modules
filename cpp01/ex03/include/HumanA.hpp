#ifndef HUMANA_HPP
# define HUMANA_HPP

/* -- Includes -- */
#include "Weapon.hpp"

/* -- Class -- */
class HumanA
{
private:
	const std::string	_name;
	Weapon&				_weapon;

public:
	HumanA( const std::string& name, Weapon& weapon );
	~HumanA();

	void	attack( void ) const;
};

#endif