#include "Ice.hpp"
#include <iostream>

/* -- Constructors -- */
Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& toCopy) : AMateria("ice") { (void)toCopy; }

/* -- Destructor -- */
Ice::~Ice() {}

/* -- Assignment operator -- */
Ice& Ice::operator=(const Ice& other)
{
	(void)other;
	return (*this);
}

/* -- Methods -- */
AMateria* Ice::clone() const { return (new Ice(*this)); }

void Ice::use(ICharacter& target) { std::cout << "\e[1m* shoots an ice bolt at " << target.getName() << " *\e[0m\n"; }
