#include <iostream>
#include "AMateria.hpp"

/* -- Constructors -- */
AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& other) : _type(other._type) {}

/* -- Destrcutor -- */
AMateria::~AMateria() {}

/* -- Assignment operator -- */
AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
		_type = other._type;

	return (*this);
}

/* -- Getter -- */
const std::string& AMateria::getType() const { return (_type); }

/* -- Methods -- */
void AMateria::use(ICharacter& target)
{
	std::cout << "* use of materia " << _type << " on " << target.getName() << " *\n";
}
