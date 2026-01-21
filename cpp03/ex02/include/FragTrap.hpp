#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

/* -- Includes -- */
#include "ClapTrap.hpp"

/* -- Colors -- */
#define HIGHFIVE	"\e[38;2;210;255;210;1m"

/* -- Class -- */
class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& toCopy);

	~FragTrap();

	FragTrap&	operator=(const FragTrap& other);

	void	highFiveGuys(void);						// <- new

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	attack(const std::string& target);
};

# endif
