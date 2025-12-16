#ifndef ICE_HPP
# define ICE_HPP

/* -- Includes -- */
#include "AMateria.hpp"

/* -- Colors -- */
#define NEW_ICE	"\e[38;2;130;240;255;1m"
#define DES_ICE	"\e[38;2;80;120;170;1m"

/* -- Class -- */
class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice& toCopy);

	~Ice();

	Ice&	operator=(const Ice& other);

	void	use(ICharacter& target);
};

#endif