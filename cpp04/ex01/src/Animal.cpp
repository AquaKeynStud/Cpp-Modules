#include <iostream>
#include "Animal.hpp"

/* -- Constuctors -- */
Animal::Animal() : type("Hallucigenia")
{
	std::cout << GREEN << "New living organism created.\n" << RESET;
}

Animal::Animal(const std::string& name) : type(name)
{
	std::cout << GREEN << "New animal (" << type << ") created.\n" << RESET;
}

Animal::Animal(const Animal& toCopy) : type(toCopy.getType())
{
	std::cout << GREEN << "New copy of animal (" << type << ") created.\n" << RESET;
}

/* -- Destructor -- */
Animal::~Animal()
{
	std::cout << RED << "Animal of type (" << type << ") destroyed.\n" << RESET;
}

/* -- Operators -- */
Animal& Animal::operator=(const Animal& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	return (*this);
}

/* -- Getters -- */
const std::string& Animal::getType() const { return (type); }

/* -- Methods -- */
void Animal::makeSound() const { std::cout << "\n"; }
