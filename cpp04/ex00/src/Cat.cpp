#include <iostream>
#include "Cat.hpp"

/* -- Constuctors -- */
Cat::Cat() : Animal("Cat 🙀")
{
	std::cout << GREEN << "🐈 New Cat created 🐈\n" << RESET;
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy)
{
	std::cout << GREEN << "🐈 New copy of Cat created 🐈\n" << RESET;
}

/* -- Destructor -- */
Cat::~Cat()
{
	std::cout << RED << "😿 Cat destroyed 😿\n" << RESET;
}

/* -- Operators -- */
Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	return (*this);
}

/* -- Getters -- */
const std::string& Cat::getType() const { return (type); }

/* -- Methods -- */
void Cat::makeSound(void) const { std::cout << SOUND << "😺 Meow! 😺\n" << RESET; }
