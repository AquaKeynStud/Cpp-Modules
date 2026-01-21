#include <iostream>
#include "FragTrap.hpp"

/* -- Constructors -- */
FragTrap::FragTrap()
	:	ClapTrap("Frag")
{
	_hit_pts = 100;
	_energy_pts = 100;
	_attack_dmg = 30;

	std::cout << GREEN "🎍 FragTrap " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

FragTrap::FragTrap(const std::string& name)
	:	ClapTrap(name)
{
	_hit_pts = 100;
	_energy_pts = 100;
	_attack_dmg = 30;

	std::cout << GREEN "🎍 FragTrap🔪 " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

FragTrap::FragTrap(const FragTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << GREEN "🎋 FragTrap🔪 " BOLD << _name;
	std::cout << GREEN " copied ! 🎋" RESET;
}

/* -- Destructor -- */
FragTrap::~FragTrap()
{
	std::cout << RED << "🍁 FragTrap🔪 " BOLD << _name;
	std::cout << RED << " destroyed ! 🍁" RESET;
}

/* -- Assignment operator -- */
FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (not (this == &other))
		ClapTrap::operator=(other);

	return (*this);
}

/* -- Public Methods -- */
void FragTrap::takeDamage(unsigned int amount)
{
	if (not _hit_pts)
	{
		std::cout << RED "📛 FragTrap " BOLD << _name << RED " is already dead ! 📛" RESET;
		return;
	}

	std::cout << DMGS "🧨 FragTrap " BOLD << _name << DMGS " took " RED;
	std::cout << amount << DMGS " damages. 🧨" RESET;

	if (amount > _hit_pts)
		amount = _hit_pts;
	_hit_pts -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (not _hit_pts or not _energy_pts)
	{
		std::cout << RED "📛 FragTrap " BOLD << _name << RED;
		std::cout << (_hit_pts ? " is exhausted ! 📛" : " is dead ! 📛") << RESET;
		return;
	}

	std::cout << HEAL "♻️ FragTrap " BOLD << _name;
	std::cout << HEAL " repaired itself from " RED << amount << HEAL " damages. ♻️" RESET;

	_energy_pts--;
	_hit_pts += amount;
}

void FragTrap::attack(const std::string& target)
{
	if (not _hit_pts or not _energy_pts)
	{
		std::cout << RED "📛 FragTrap " BOLD << _name << RED;
		std::cout << (_hit_pts ? " is exhausted ! 📛" : " is dead ! 📛") << RESET;
		return;
	}

	_energy_pts--;

	std::cout << ATTK "💣 FragTrap " BOLD << _name;
	std::cout << ATTK " inflits " RED << _attack_dmg << ATTK " damages to " BOLD;
	std::cout << target << ATTK ". 💣" RESET;
}

/* -- New ex02 -- */
void FragTrap::highFiveGuys(void)
{
	if (not _hit_pts)
	{
		std::cout << RED "📛 FragTrap " BOLD << _name << RED " is already dead ! 📛" RESET;
		return;
	}

	std::cout << HIGHFIVE << "🕊️ FragTrap " BOLD << _name;
	std::cout << HIGHFIVE << " wants a high five ! 🕊️" RESET;
}