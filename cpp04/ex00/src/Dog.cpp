#include <iostream>
#include "Dog.hpp"

/* -- Constuctors -- */
Dog::Dog() : Animal("Dog 🐩")
{
	std::cout << GREEN << "🦮 New dog created 🦮\n" << RESET;
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy)
{
	std::cout << GREEN << "🦮 New copy of Dog created 🦮\n" << RESET;
}

/* -- Destructor -- */
Dog::~Dog()
{
	std::cout << RED << "🐕‍🦺 Dog destroyed 🐕‍🦺\n" << RESET;
}

/* -- Operators -- */
Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	return (*this);
}

/* -- Getters -- */
const std::string& Dog::getType() const { return (type); }

/* -- Methods -- */
void Dog::makeSound(void) const { std::cout << SOUND << "🐕 Bark! 🐕\n" << RESET; }
