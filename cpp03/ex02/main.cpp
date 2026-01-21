#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap a;
	ScavTrap b;
	FragTrap c;

	a.takeDamage(2);
	a.beRepaired(1);

	b.guardGate();
	c.highFiveGuys();

	c.attack("Another FragTrap");
	c.takeDamage(5);
	c.beRepaired(20);
	c.takeDamage(80000);
	c.highFiveGuys();

	b.attack("Frag");

	return (0);
}
