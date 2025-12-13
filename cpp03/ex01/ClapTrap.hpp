#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/* -- Includes -- */
#include <string>

/* -- Colors -- */
#define BOLD	"\e[0;1m"
#define	RESET	"\e[0m\n"

#define	RED		"\e[31;1m"
#define	GREEN	"\e[32;1m"

#define HEAL	"\e[38;2;150;255;190;1m"
#define ATTK	"\e[38;2;200;150;255;1m"
#define DMGS	"\e[38;2;200;0;0;1m"

/* -- Class -- */
class ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hit_pts;
	unsigned int	_energy_pts;
	unsigned int	_attack_dmg;

public:
// Constructors //
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& toCopy);

// Destructor //
	virtual ~ClapTrap();

// Assignment operator //
	ClapTrap&	operator=(const ClapTrap& other);

// Getters //
	const std::string&	getName() const;
	int					getHitPts() const;
	int					getEnergyPts() const;
	int					getAttackDmg() const;

// Methods //
	void				takeDamage(unsigned int amount);
	void				beRepaired(unsigned int amount);
	virtual void		attack(const std::string& target);

// Setters //
	void				subtractHitPoints(unsigned int amount);

};

#endif