#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::cout << "\e[34;1mTest casse n°1: \e[0m\n";
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	std::cout << "\n\e[34;1mTest casse n°2: \e[0m" << std::endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return (0);
}
