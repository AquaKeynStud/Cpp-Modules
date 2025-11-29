#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

/* -- Includes -- */
#include "ClapTrap.hpp"

/* -- Colors -- */
#define HIGHFIVE	"\e[38;2;210;255;210;1m"

class FragTrap : public ClapTrap
{
public:
// Constructors //
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& toCopy);

// Destructor //
	~FragTrap();

// Assignment operator //
	FragTrap&	operator=(const FragTrap& other);

// Methods //
	void	highFiveGuys(void);

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	attack(const std::string& target);
};

# endif
