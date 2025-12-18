#include "Cure.hpp"
#include <iostream>

/* -- Constructors -- */
Cure::Cure() : AMateria("cure") { std::cout << NEW_CURE << "🔋 New Cure materia created ! 🔋" << RESET; }

Cure::Cure(const Cure& toCopy) : AMateria("cure") { std::cout << NEW_CURE << "🔋 New copy of Cure materia created ! 🔋" << RESET; }

/* -- Destructor -- */
Cure::~Cure() { std::cout << DES_CURE << "🍈 Cure materia destroyed 🍈" << RESET; }

/* -- Assignment operator -- */
Cure& Cure::operator=(const Cure& other) { return (*this); }

/* -- Methods -- */
AMateria* Cure::clone() const { return (new Cure(*this)); }

void Cure::use(ICharacter& target) { std::cout << "\e[1m* heals " << target.getName() << "'s wounds *\e[0m\n"; }
