#include <iostream>
#include "DiamondTrap.hpp"

/* -- Constructors -- */
DiamondTrap::DiamondTrap()
	:	ClapTrap("Diamond_clap_name"),
		ScavTrap("Diamond"),
		FragTrap("Diamond"),
		_name("Diamond")
{
	_hit_pts = f_hit_pts;
	_energy_pts = s_energy_pts;
	_attack_dmg = f_attack_dmg;

	std::cout << GREEN "🎍 DiamondTrap🎎 " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

DiamondTrap::DiamondTrap(const std::string& name)
	:	ClapTrap(name + "_clap_name"),
		ScavTrap(name),
		FragTrap(name),
		_name(name)
{
	_hit_pts = f_hit_pts;
	_energy_pts = s_energy_pts;
	_attack_dmg = f_attack_dmg;

	std::cout << GREEN "🎍 DiamondTrap🎎 " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

DiamondTrap::DiamondTrap(const DiamondTrap& toCopy)
	:	ClapTrap(toCopy),
		ScavTrap(toCopy),
		FragTrap(toCopy),
		_name(toCopy._name)
{
	std::cout << GREEN "🎋 DiamondTrap🎎 " BOLD << _name;
	std::cout << GREEN " copied ! 🎋" RESET;
}

/* -- Destructor -- */
DiamondTrap::~DiamondTrap()
{
	std::cout << RED "🍁 DiamondTrap🎎 " BOLD << _name;
	std::cout << RED " destroyed ! 🍁" RESET;
}

/* -- Assignment operator -- */
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	if (not (this == &other))
		ClapTrap::operator=(other);

	return (*this);
}

/* -- Methods -- */
void DiamondTrap::whoAmI()
{
	std::cout << GREET "🔰 DiamondTrap : Hi :D! I'm 💎 " NAME << _name;
	std::cout << GREET " 💎!\n                 But my serial number is: " BOLD << ClapTrap::_name << RESET;
}
