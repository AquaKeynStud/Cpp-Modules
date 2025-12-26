#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

/* -- Includes -- */
#include "IMateriaSource.hpp"

/* -- Colors -- */
#define MAT_CREATE	"\e[2;38;255;240;150;1m"
#define MAT_DESTROY	"\e[2;38;255;185;150;1m"

/* -- Class -- */
class MateriaSource : public IMateriaSource
{
public:
// Constructors //
	MateriaSource();
	MateriaSource(const MateriaSource& toCopy);

// Destructor //
	~MateriaSource();

// Assignment operator //
	MateriaSource&	operator=(const MateriaSource& other);

// Methods //
	void			learnMateria(AMateria*);
	AMateria*		createMateria(std::string const & type);

private:
	AMateria*	_storage[4];
};

#endif