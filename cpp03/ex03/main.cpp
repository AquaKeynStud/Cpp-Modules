#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
	ClapTrap a("Clap");
	ScavTrap b("Scav");
	FragTrap c("Frag");
	DiamondTrap d("Diamond");

	std::cout << "A energy: " << a.getEnergyPts() << std::endl;
	a.takeDamage(2);
	a.beRepaired(1);
	std::cout << "A energy: " << a.getEnergyPts() << std::endl;

	std::cout << c.getHitPts() << " must be the same as " << d.getHitPts() << std::endl;
	std::cout << b.getEnergyPts() << " must be the same as " << d.getEnergyPts() << std::endl;
	std::cout << c.getAttackDmg() << " must be the same as " << d.getAttackDmg() << std::endl;

	b.guardGate();
	c.highFiveGuys();

	b.attack("Frag");
	c.takeDamage(b.getAttackDmg());
	std::cout << "Frag Hit Pts: " << c.getHitPts() << std::endl;

	d.attack(a.getName());
	d.whoAmI();
	return (0);
}
