#include <iostream>
#include "Dog.hpp"

/* -- Constuctors -- */
Dog::Dog() : Animal("Dog 🐩"), _brain(new Brain())
{
	std::cout << GREEN << "🦮 New dog created 🦮\n" << RESET;
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy), _brain(new Brain(*toCopy._brain))
{
	std::cout << GREEN << "🦮 New copy of Dog created 🦮\n" << RESET;
}

/* -- Destructor -- */
Dog::~Dog()
{
	delete _brain;

	std::cout << RED << "🐕‍🦺 Dog destroyed 🐕‍🦺\n" << RESET;
}

/* -- Operators -- */
Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	delete _brain;
	_brain = new Brain(*other._brain);

	return (*this);
}

/* -- Getters -- */
const std::string& Dog::getType() const { return (type); }

/* -- Methods -- */
void Dog::makeSound(void) const { std::cout << SOUND << "🐕 Bark! 🐕\n" << RESET; }

Brain& Dog::getBrain() { return (*_brain); }
