#include "Zombie.hpp"

int main(void)
{
	Zombie	z1;
	Zombie	z2("Bruno");

	Zombie*	z3 = newZombie("Heap");

	z1.announce();
	z2.announce();
	z3->announce();

	randomChump("Random");

	delete z3;

	return (0);
}
