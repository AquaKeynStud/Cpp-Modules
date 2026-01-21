#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

/* -- Includes -- */
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* -- Colors -- */
#define NAME	"\e[38;2;110;180;210;1m"
#define GREET	"\e[38;2;240;255;170;1m"

/* -- Class -- */
class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;

public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& toCopy);

	~DiamondTrap();

	DiamondTrap&	operator=(const DiamondTrap& other);

	void	whoAmI(void);
	using	ScavTrap::attack;
};

#endif