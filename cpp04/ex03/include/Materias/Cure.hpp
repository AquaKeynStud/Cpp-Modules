#ifndef CURE_HPP
# define CURE_HPP

/* -- Includes -- */
#include "AMateria.hpp"

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