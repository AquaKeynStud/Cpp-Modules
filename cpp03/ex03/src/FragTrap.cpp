#include <iostream>
#include "FragTrap.hpp"

/* -- Constructors -- */
FragTrap::FragTrap(const std::string& name)
	:	ClapTrap(name)
{
	_hit_pts = f_hit_pts;
	_energy_pts = 100;
	_attack_dmg = f_attack_dmg;

	std::cout << GREEN << "🎍 FragTrap ";
	std::cout << BOLD << _name;
	std::cout << GREEN << " created ! 🎍";
	std::cout << RESET;
}

FragTrap::FragTrap(const FragTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << GREEN << "🎋 FragTrap ";
	std::cout << BOLD << _name;
	std::cout << GREEN << " copied ! 🎋";
	std::cout << RESET;
}

/* -- Destructor -- */
FragTrap::~FragTrap()
{
	std::cout << RED << "🍁 FragTrap ";
	std::cout << BOLD << _name;
	std::cout << RED << " destroyed ! 🍁";
	std::cout << RESET;
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
	if (not _energy_pts or not _hit_pts)
		return;

	std::cout << DMGS << "🧨 FragTrap ";
	std::cout << BOLD << _name;
	std::cout << DMGS << " took ";
	std::cout << RED << amount;
	std::cout << DMGS << " damages. 🧨";
	std::cout << RESET;

	_hit_pts -= amount;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (not _energy_pts or not _hit_pts)
		return;

	std::cout << HEAL << "♻️ FragTrap ";
	std::cout << BOLD << _name;
	std::cout << HEAL << " repaired itself from ";
	std::cout << RED << amount;
	std::cout << HEAL << " damages. ♻️";
	std::cout << RESET;

	_energy_pts--;
	_hit_pts += amount;
}

void FragTrap::attack(const std::string& target)
{
	if (not _energy_pts or not _hit_pts)
		return;

	_energy_pts--;

	std::cout << ATTK << "💣 FragTrap ";
	std::cout << BOLD << _name;
	std::cout << ATTK << " inflits ";
	std::cout << RED << _attack_dmg;
	std::cout << ATTK << " damages to ";
	std::cout << BOLD << target;
	std::cout << ATTK << ". 💣";
	std::cout << RESET;
}

/* -- New ex02 -- */
void FragTrap::highFiveGuys(void)
{
	std::cout << HIGHFIVE << "🕊️ FragTrap ";
	std::cout << BOLD << _name;
	std::cout << HIGHFIVE << " wants a high five ! 🕊️";
	std::cout << RESET;
}