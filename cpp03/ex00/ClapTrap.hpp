#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

/* -- Includes -- */
#include <string>

/* -- Macros -- */
#define BOLD	"\e[0;1m"
#define	RESET	"\e[0m\n"

#define	RED		"\e[31;1m"
#define	GREEN	"\e[32;1m"

#define HEAL	"\e[38;2;130;255;190;1m"
#define ATTK	"\e[38;2;200;150;255;1m"
#define DMGS	"\e[38;2;200;0;0;1m"

/* -- Class -- */
class ClapTrap
{
private:
	std::string	_name;
	int			_hit_pts;
	int			_energy_pts;
	int			_attack_dmg;

public:
// Constructors //
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& toCopy);

// Destructor //
	~ClapTrap();

// Assignment operator //
	ClapTrap&	operator=(const ClapTrap& other);

// Getters //
	const std::string&	getName() const;
	int				getHitPts() const;
	int				getEnergyPts() const;
	int				getAttackDmg() const;

// Methods //
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void	attack(const std::string& target);

};

#endif