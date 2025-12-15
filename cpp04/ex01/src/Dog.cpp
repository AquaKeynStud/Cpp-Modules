#include <iostream>
#include "Dog.hpp"

/* -- Constuctors -- */
Dog::Dog() : Animal("Dog 🐩"), _brain(new Brain())									// <- new
{
	std::cout << GREEN << "🦮 New dog created 🦮\n" << RESET;
}

Dog::Dog(const Dog& toCopy) : Animal(toCopy), _brain(new Brain(*toCopy._brain))		// <- new
{
	std::cout << GREEN << "🦮 New copy of Dog created 🦮\n" << RESET;
}

/* -- Destructor -- */
Dog::~Dog()
{
	delete _brain;																	// <- new

	std::cout << RED << "🐕‍🦺 Dog destroyed 🐕‍🦺\n" << RESET;
}

/* -- Operators -- */
Dog& Dog::operator=(const Dog& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	delete _brain;																	// <- new
	_brain = new Brain(*other._brain);												// <- new

	return (*this);
}

/* -- Getters -- */
const std::string& Dog::getType() const { return (type); }

/* -- Methods -- */
void Dog::makeSound(void) const { std::cout << SOUND << "🐕 Bark! 🐕\n" << RESET; }

Brain& Dog::getBrain() { return (*_brain); }										// <- new
