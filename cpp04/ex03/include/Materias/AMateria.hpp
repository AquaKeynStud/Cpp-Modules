#ifndef AMATERIA_HPP
# define AMATERIA_HPP

/* -- Includes -- */
#include <string>
#include "ICharacter.hpp"

/* -- Colors -- */
#define RESET	"\e[0m\n"

/* -- Class -- */
class AMateria
{
protected:
	std::string	_type;

public:
	AMateria(std::string const & type);
	AMateria(AMateria const & other);						// <- new

	virtual ~AMateria(void);								// <- new
	
	AMateria & operator=(AMateria const & other);			// <- new


	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif
