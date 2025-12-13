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
// Constructors //
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& toCopy);

// Destructor //
	virtual ~DiamondTrap();

// Assignment operator //
	DiamondTrap&	operator=(const DiamondTrap& other);

// Methods //
	void	attack(const std::string& name);
	void	whoAmI(void);
};

#endif