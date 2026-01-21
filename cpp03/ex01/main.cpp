#include <iostream>
#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("First");
	ScavTrap b("Second");
	ScavTrap c(b);

	a.attack("Another ScavTrap");
	a.takeDamage(2);
	a.beRepaired(1);

	b = a;

	a.guardGate();
	a.takeDamage(200000);
	a.guardGate();


	return (0);
}
