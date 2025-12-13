#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

// #pragma once // alternative aux include guards

/* -- Includes -- */
#include "ClapTrap.hpp"

/* -- Colors -- */
#define GATEKEEP	"\e[38;2;135;255;255;1m"

class ScavTrap : virtual public ClapTrap
{
protected:
	static const unsigned int	s_energy_pts = 50;

public:
// Constructors //
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& toCopy);

// Destructor //
	virtual ~ScavTrap();

// Assignment operator //
	ScavTrap&	operator=(const ScavTrap& other);

// Methods //
	void	guardGate();

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	attack(const std::string& target);
};

# endif
