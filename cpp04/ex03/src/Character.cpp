#include <iostream>
#include "Character.hpp"

/* -- Constructor -- */
Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;

	std::cout << CREATE << "🎎 New character named '" << name << "' is born 🎎" << RESET;
}

/* -- Copy Constructor -- */
Character::Character(const Character& toCopy) : _name(toCopy._name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = *toCopy._inventory[i];

	std::cout << CREATE << "🎎 New clone of character named '" << toCopy._name << "' is born  🎎" << RESET;
}

/* -- Destructor -- */
Character::~Character() { std::cout << DESTROY << "🪦 Character '" << _name << "' died...  🪦" << RESET; }

/* -- Assignment operator -- */
Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);

	_name = other._name;
	for (int i = 0; i < 4; i++)
		*_inventory[i] = *other._inventory[i];

	return (*this);
}

/* -- Getters -- */
const std::string& Character::getName() const { return (_name); }

/* -- Methods -- */
void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	
	for (int i = 0; i < 4; i++)
		if (not _inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
}
