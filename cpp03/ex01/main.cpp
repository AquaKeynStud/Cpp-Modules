#include <iostream>
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("First");
	ScavTrap b("Second");
	ScavTrap c(b);

	std::cout << "A energy: " << a.getEnergyPts() << std::endl;
	a.takeDamage(2);
	a.beRepaired(1);
	std::cout << "A energy: " << a.getEnergyPts() << std::endl;

	std::cout << "C name (copy constructor): " << c.getName() << std::endl;
	std::cout << "A hits points before the attack: " << a.getHitPts() << std::endl;
	c.attack(a.getName());
	a.subtractHitPoints(c.getAttackDmg());
	std::cout << "A hit points: " << a.getHitPts() << std::endl;

	std::cout << "B name before =: " << b.getName() << std::endl;
	b = a;
	std::cout << "B name after =: " << b.getName() << std::endl;

	a.guardGate();
}
