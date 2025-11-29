#include <iostream>
#include "ScavTrap.hpp"

/* -- Constructors -- */
ScavTrap::ScavTrap(const std::string& name)
	:	ClapTrap(name)
{
	_hit_pts = 100;
	_energy_pts = 50;
	_attack_dmg = 20;

	std::cout << GREEN << "🎍 ScavTrap ";
	std::cout << BOLD << _name;
	std::cout << GREEN << " created ! 🎍";
	std::cout << RESET;
}

ScavTrap::ScavTrap(const ScavTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << GREEN << "🎋 ScavTrap ";
	std::cout << BOLD << _name;
	std::cout << GREEN << " copied ! 🎋";
	std::cout << RESET;
}

/* -- Destructor -- */
ScavTrap::~ScavTrap()
{
	std::cout << RED << "🍁 ScavTrap ";
	std::cout << BOLD << _name;
	std::cout << RED << " destroyed ! 🍁";
	std::cout << RESET;
}

/* -- Assignment operator -- */
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (not (this == &other))
		ClapTrap::operator=(other);

	return (*this);
}

/* -- Public Methods -- */
void ScavTrap::takeDamage(unsigned int amount)
{
	if (not _energy_pts or not _hit_pts)
		return;

	std::cout << DMGS << "🧨 ScavTrap ";
	std::cout << BOLD << _name;
	std::cout << DMGS << " took ";
	std::cout << RED << amount;
	std::cout << DMGS << " damages. 🧨";
	std::cout << RESET;

	_hit_pts -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (not _energy_pts or not _hit_pts)
		return;

	std::cout << HEAL << "♻️ ScavTrap ";
	std::cout << BOLD << _name;
	std::cout << HEAL << " repaired itself from ";
	std::cout << RED << amount;
	std::cout << HEAL << " damages. ♻️";
	std::cout << RESET;

	_energy_pts--;
	_hit_pts += amount;
}

void ScavTrap::attack(const std::string& target)
{
	if (not _energy_pts or not _hit_pts)
		return;

	_energy_pts--;

	std::cout << ATTK << "💣 ScavTrap ";
	std::cout << BOLD << _name;
	std::cout << ATTK << " inflits ";
	std::cout << RED << _attack_dmg;
	std::cout << ATTK << " damages to ";
	std::cout << BOLD << target;
	std::cout << ATTK << ". 💣";
	std::cout << RESET;
}

/* -- New ex01 -- */
void ScavTrap::guardGate()
{
	if (not _energy_pts or not _hit_pts)
		return;

	std::cout << GATEKEEP << "🛡️ ScavTrap ";
	std::cout << BOLD << _name;
	std::cout << GATEKEEP << " enters Gatekeeper mode. 🛡️";
	std::cout << RESET;
}