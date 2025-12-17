#ifndef CURE_HPP
# define CURE_HPP

/* -- Includes -- */
#include "AMateria.hpp"

/* -- Colors -- */
#define NEW_CURE	"\e[38;2;160;250;150;1m"
#define DES_CURE	"\e[38;2;80;170;80;1m"

/* -- Class -- */
class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure& toCopy);

	~Cure();

	Cure&	operator=(const Cure& other);

	void	use(ICharacter& target);
};

#endif