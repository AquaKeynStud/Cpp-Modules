#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

/* -- Includes -- */
#include "ClapTrap.hpp"

/* -- Colors -- */
#define HIGHFIVE	"\e[38;2;210;255;210;1m"

class FragTrap : virtual public ClapTrap
{
protected:
	static const unsigned int	f_hit_pts = 100;
	static const unsigned int	f_attack_dmg = 30;

public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& toCopy);

	~FragTrap();

	FragTrap&	operator=(const FragTrap& other);

	void	highFiveGuys(void);

	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	attack(const std::string& target);
};

# endif
