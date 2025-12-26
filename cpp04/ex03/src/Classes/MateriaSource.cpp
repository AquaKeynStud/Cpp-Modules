#include <iostream>
#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		_storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& toCopy)
{
	*this = toCopy;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_storage[i])
			delete _storage[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this == &other)
		return (*this);

	for (int i = 0; i < 4; i++)
	{
		if (other._storage[i])
			_storage[i] = other._storage[i]->clone();
		else
			_storage[i] = NULL;
	}

	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (!m)
		return ;
	
	for (int i = 0; i < 4; i++)
	{
		if (not _storage[i])
		{
			_storage[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
		if (_storage[i] and _storage[i]->getType() == type)
			return (_storage[i]->clone());

	return (NULL);
}
