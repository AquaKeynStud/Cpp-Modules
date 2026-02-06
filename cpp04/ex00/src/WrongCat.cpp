#include <iostream>
#include "Animal.hpp"
#include "WrongCat.hpp"

/* -- Constuctors -- */
WrongCat::WrongCat() : WrongAnimal("Cat 🙀")
{
	std::cout << GREEN << "🐈 New Cat created 🐈\n" << RESET;
}

WrongCat::WrongCat(const WrongCat& toCopy) : WrongAnimal(toCopy)
{
	std::cout << GREEN << "🐈 New copy of Cat created 🐈\n" << RESET;
}

/* -- Destructor -- */
WrongCat::~WrongCat()
{
	std::cout << RED << "😿 Cat destroyed 😿\n" << RESET;
}

/* -- Operators -- */
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	return (*this);
}

/* -- Getters -- */
const std::string& WrongCat::getType() const { return (type); }
