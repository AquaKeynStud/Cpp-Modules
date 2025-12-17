#include "Ice.hpp"
#include <iostream>

/* -- Constructors -- */
Ice::Ice() : AMateria("ice") { std::cout << NEW_ICE << "❄️ New Ice materia created ! ❄️" << RESET; }

Ice::Ice(const Ice& toCopy) : AMateria("ice") { std::cout << NEW_ICE << "❄️ New copy of Ice materia created ! ❄️" << RESET; }

/* -- Destructor -- */
Ice::~Ice() { std::cout << DES_ICE << "🧊 Ice materia destroyed 🧊" << RESET; }

/* -- Assignment operator -- */
Ice& Ice::operator=(const Ice& other) { return (*this); }

/* -- Methods -- */
void Ice::use(ICharacter& target) { std::cout << "\e[1m* shoots an ice bolt at " << target.getName() << " *\e[0m\n"; }
