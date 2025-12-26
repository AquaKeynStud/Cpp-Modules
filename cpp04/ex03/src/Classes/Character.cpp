#include <iostream>
#include "Character.hpp"

/* -- Constructor -- */
Character::Character(const std::string& name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

/* -- Copy Constructor -- */
Character::Character(const Character& toCopy) : _name(toCopy._name)
{
	for (int i = 0; i < 4; i++)
	{
		_inventory[i] = NULL;
		if (_inventory[i])
			_inventory[i] = toCopy._inventory[i]->clone();
	}
}

/* -- Destructor -- */
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
}

/* -- Assignment operator -- */
Character& Character::operator=(const Character& other)
{
	if (this == &other)
		return (*this);

	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];

		_inventory[i] = NULL;
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}

	return (*this);
}

/* -- Getters -- */
const std::string& Character::getName() const { return (_name); }

/* -- Methods -- */
void Character::unequip(int idx)
{
	if (idx < 0 or idx > 3)
		return ;

	if (_inventory[idx])
		_inventory[idx] = NULL;
}

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

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 or idx > 3 or not _inventory[idx])
		return ;
	
	_inventory[idx]->use(target);
}
