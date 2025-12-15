#include <iostream>
#include "Cat.hpp"

/* -- Constuctors -- */
Cat::Cat() : Animal("Cat 🙀"), _brain(new Brain())
{
	std::cout << GREEN << "🐈 New Cat created 🐈\n" << RESET;
}

Cat::Cat(const Cat& toCopy) : Animal(toCopy), _brain(new Brain(*toCopy._brain))
{
	std::cout << GREEN << "🐈 New copy of Cat created 🐈\n" << RESET;
}

/* -- Destructor -- */
Cat::~Cat()
{
	delete _brain;

	std::cout << RED << "😿 Cat destroyed 😿\n" << RESET;
}

/* -- Operators -- */
Cat& Cat::operator=(const Cat& other)
{
	if (this == &other)
		return (*this);
	this->type = other.getType();

	delete _brain;
	_brain = new Brain(*other._brain);

	return (*this);
}

/* -- Getters -- */
const std::string& Cat::getType() const { return (type); }

/* -- Methods -- */
void Cat::makeSound(void) const { std::cout << SOUND << "😺 Meow! 😺\n" << RESET; }

Brain& Cat::getBrain() { return (*_brain); }
