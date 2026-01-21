#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	// ClapTrap a("Clap");
	// ScavTrap b("Scav");
	// FragTrap c("Frag");
	DiamondTrap d("Diamond");

	// a.takeDamage(2);
	// a.beRepaired(1);

	// b.guardGate();
	// c.highFiveGuys();

	// b.attack("Frag");

	d.attack("Another DiamondTrap");
	d.whoAmI();

	return (0);
}
