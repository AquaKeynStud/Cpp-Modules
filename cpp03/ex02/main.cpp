#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a("Clap");
	ScavTrap b("Scav");
	FragTrap c("Frag");

	std::cout << "A energy: " << a.getEnergyPts() << std::endl;
	a.takeDamage(2);
	a.beRepaired(1);
	std::cout << "A energy: " << a.getEnergyPts() << std::endl;

	b.guardGate();
	c.highFiveGuys();

	b.attack("Frag");
	c.takeDamage(b.getAttackDmg());
	std::cout << "Frag Hit Pts: " << c.getHitPts() << std::endl;
}
