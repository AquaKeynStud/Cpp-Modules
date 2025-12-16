#include "Ice.hpp"
#include <iostream>

/* -- Constructors -- */
Ice::Ice() : AMateria("ice") { std::cout << NEW_ICE << "❄️ New Ice materia created ! ❄️" << RESET; }

Ice::Ice(const Ice& toCopy) : AMateria("ice") { std::cout << NEW_ICE << "❄️ New copy of Ice materia created ! ❄️" << RESET; }

/* -- Destructor -- */
Ice::~Ice() { std::cout << DES_ICE << "🧊 Ice materia destroyed 🧊" << RESET; }

/* -- Assignment operator -- */
Ice& Ice::operator=(const Ice& other)
{
	if (this == &other)
		return (*this);

	_type = "ice";

	return (*this);
}
