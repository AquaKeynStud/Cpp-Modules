#include "Zombie.hpp"

int main(void)
{
	int		horde_size = 5;
	Zombie*	horde = zombieHorde(horde_size, "Dummy");

	for (int i = 0; i < horde_size; i++)
		if (i % 2)
			horde[i].announce();

	delete[] horde;

	return (0);
}
