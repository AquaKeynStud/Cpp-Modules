#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

static void animals()
{
	Animal hallu;
	Animal otter("Otter");
	Animal otter2(otter);

	std::cout << "\e[1m\n╭━━━━══╕🦢 Animal tests 🦢╒══━━━━╮\n";
	std::cout << hallu.getType() << '\n';
	std::cout << otter.getType() << '\n';
	std::cout << otter2.getType() << '\n';

	std::cout << "\nReassignment of otter2...\n";
	otter2 = hallu;
	std::cout << otter2.getType() << '\n';
	std::cout << "╰━━━━══╛🦢 ------------ 🦢╘══━━━━╯\e[0m\n\n";
}

static void dogs()
{
	Dog Rex;
	Dog Milk(Rex);

	std::cout << "\e[1m\n╭━━━━══╕🦴 Dog tests 🦴╒══━━━━╮\n";
	std::cout << "Rex is a: " << Rex.getType() << '\n';
	std::cout << "Milk is a: " << Milk.getType() << "\n\n";

	std::cout << "Rex: ";
	Rex.makeSound();
	std::cout << "\e[1mMilk: ";
	Milk.makeSound();
	std::cout << "╰━━━━══╛🦴 --------- 🦴╘══━━━━╯\e[0m\n\n";
}

static void cats()
{
	Cat Tsuki;
	Cat Guily(Tsuki);

	std::cout << "\e[1m\n╭━━━━══╕🧶 Cat tests 🧶╒══━━━━╮\n";
	std::cout << "Tsuki is a: " << Tsuki.getType() << '\n';
	std::cout << "Guily is a: " << Guily.getType() << "\n\n";

	std::cout << "Tsuki: ";
	Tsuki.makeSound();
	std::cout << "\e[1mGuily: ";
	Guily.makeSound();
	std::cout << "╰━━━━══╛🧶 --------- 🧶╘══━━━━╯\e[0m\n\n";
}

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete i;
	delete j;
	delete meta;

	std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
	animals();
	std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
	dogs();
	std::cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
	cats();
}
