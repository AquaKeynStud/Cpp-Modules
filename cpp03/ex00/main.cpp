#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("First");
	ClapTrap b("Second");
	ClapTrap c(b);

	std::cout << "A energy: " << a.getEnergyPts() << std::endl;
	a.takeDamage(2);
	a.beRepaired(1);
	std::cout << "A energy: " << a.getEnergyPts() << std::endl;

	std::cout << "C name: " << c.getName() << std::endl;
	c.attack(a.getName());

	std::cout << "B name before =: " << b.getName() << std::endl;
	b = a;
		std::cout << "B name after =: " << b.getName() << std::endl;
}
