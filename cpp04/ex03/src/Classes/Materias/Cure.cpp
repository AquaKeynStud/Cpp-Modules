#include "Cure.hpp"
#include <iostream>

/* -- Constructors -- */
Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& toCopy) : AMateria("cure") { (void)toCopy; }

/* -- Destructor -- */
Cure::~Cure() {}

/* -- Assignment operator -- */
Cure& Cure::operator=(const Cure& other)
{
	(void)other;
	return (*this);
}

/* -- Methods -- */
AMateria* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target) { std::cout << "\e[1m* heals " << target.getName() << "'s wounds *\e[0m\n"; }
