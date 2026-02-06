#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"

/* -- Constuctors -- */
WrongAnimal::WrongAnimal() : type("Hallucigenia")
{
	std::cout << GREEN << "New living organism created.\n" << RESET;
}

WrongAnimal::WrongAnimal(const std::string& name) : type(name)
{
	std::cout << GREEN << "New animal (" << type << ") created.\n" << RESET;
}

WrongAnimal::WrongAnimal(const WrongAnimal& toCopy) : type(toCopy.getType())
{
	std::cout << GREEN << "New copy of animal (" << type << ") created.\n" << RESET;
}

/* -- Destructor -- */
WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "animal of type (" << type << ") destroyed.\n" << RESET;
}

/* -- Operators -- */
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	return (*this);
}

/* -- Getters -- */
const std::string& WrongAnimal::getType() const { return (type); }

/* -- Methods -- */
void WrongAnimal::makeSound() const { std::cout << "Yayayayayayaya\n"; }
