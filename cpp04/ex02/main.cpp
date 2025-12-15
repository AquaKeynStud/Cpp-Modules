#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	ANIMAL_NBR = 3;

int main()
{

	// Animal test; // Should crash

	if (ANIMAL_NBR < 2) return (1);

	Animal* animals[ANIMAL_NBR];

	std::cout << "\n\e[1m-- [ ⚗️ CREATION OF ANIMALS ⚗️ ] --\e[0m\n\n";

	for (int i = 0; i < ANIMAL_NBR; i++)
	{
		if (i < (ANIMAL_NBR + 1) / 2)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
		std::cout << "―――――――――――――――――――――――――――――――――――――――\n";
	}


	std::cout << "\n\n\e[1m-- [ 🍡 TESTS OF THE BRAIN 🍡 ] --\e[0m\n\n\n";

	animals[0]->getBrain().setIdea(0, "Bone...");
	animals[0]->getBrain().setIdea(1, "Woof...");
	std::cout << animals[0]->getBrain().getIdea(0) << std::endl;
	std::cout << animals[0]->getBrain().getIdea(1) << std::endl;

	Dog* dog = dynamic_cast<Dog*>(animals[1]);
	if (dog)
	{
		std::cout << std::endl;
		delete animals[1];
		animals[1] = new Dog(*static_cast<Dog*>(animals[0]));
		std::cout << std::endl;

		animals[1]->getBrain().setIdea(1, "Yap Yap!");
		std::cout << animals[1]->getBrain().getIdea(0) << std::endl;
		std::cout << animals[1]->getBrain().getIdea(1) << std::endl;
	}

	Cat* cat = dynamic_cast<Cat*>(animals[(ANIMAL_NBR + 1) / 2]);
	if (cat)
	{
		animals[(ANIMAL_NBR + 1) / 2]->getBrain().setIdea(0, "Milk...");
		animals[(ANIMAL_NBR + 1) / 2]->getBrain().setIdea(1, "Meoww");
		std::cout << animals[(ANIMAL_NBR + 1) / 2]->getBrain().getIdea(0) << std::endl;
		std::cout << animals[(ANIMAL_NBR + 1) / 2]->getBrain().getIdea(1) << std::endl;
	}

	std::cout << "\n\n\e[1m-- [ 🪅 DESTRUCTION OF ANIMALS 🪅 ] --\e[0m\n\n\n";
	for (int i = 0; i < ANIMAL_NBR; i++)
	{
		delete animals[i];
		std::cout << "―――――――――――――――――――――――――――――――――――――――\n";
	}
	
	return (0);
}
