#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("First");
	ClapTrap b("Second");
	ClapTrap c(b);

	a.takeDamage(2);
	a.beRepaired(1);
	a.takeDamage(20000);
	a.beRepaired(20000);

	c.attack("First");

	b = a;

	return (0);
}
