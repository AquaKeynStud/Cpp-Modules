#include <iostream>
#include "ScavTrap.hpp"

/* -- Constructors -- */
ScavTrap::ScavTrap()
	:	ClapTrap("Scav")
{
	_hit_pts = 100;
	_energy_pts = 50;
	_attack_dmg = 20;

	std::cout << GREEN "🎍 ScavTrap🛡️ " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

ScavTrap::ScavTrap(const std::string& name)
	:	ClapTrap(name)
{
	_hit_pts = 100;
	_energy_pts = 50;
	_attack_dmg = 20;

	std::cout << GREEN "🎍 ScavTrap🛡️ " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

ScavTrap::ScavTrap(const ScavTrap& toCopy) : ClapTrap(toCopy)
{
	std::cout << GREEN "🎋 ScavTrap🛡️ " BOLD << _name;
	std::cout << GREEN " copied ! 🎋" RESET;
}

/* -- Destructor -- */
ScavTrap::~ScavTrap()
{
	std::cout << RED << "🍁 ScavTrap🛡️ " BOLD << _name;
	std::cout << RED << " destroyed ! 🍁" RESET;
}

/* -- Assignment operator -- */
ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
		ClapTrap::operator=(other);

	return (*this);
}

/* -- Public Methods -- */
void ScavTrap::takeDamage(unsigned int amount)
{
	if (not _hit_pts)
	{
		std::cout << RED "📛 ScavTrap " BOLD << _name << RED " is already dead ! 📛" RESET;
		return;
	}

	std::cout << DMGS "🧨 ScavTrap " BOLD << _name << DMGS " took " RED;
	std::cout << amount << DMGS " damages. 🧨" RESET;

	if (amount > _hit_pts)
		amount = _hit_pts;
	_hit_pts -= amount;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (not _hit_pts or not _energy_pts)
	{
		std::cout << RED "📛 ScavTrap " BOLD << _name << RED;
		std::cout << (_hit_pts ? " is exhausted ! 📛" : " is dead ! 📛") << RESET;
		return;
	}

	std::cout << HEAL "♻️ ScavTrap " BOLD << _name;
	std::cout << HEAL " repaired itself from " RED << amount << HEAL " damages. ♻️" RESET;

	_energy_pts--;
	_hit_pts += amount;
}

void ScavTrap::attack(const std::string& target)
{
	if (not _hit_pts or not _energy_pts)
	{
		std::cout << RED "📛 ScavTrap " BOLD << _name << RED;
		std::cout << (_hit_pts ? " is exhausted ! 📛" : " is dead ! 📛") << RESET;
		return;
	}

	_energy_pts--;

	std::cout << ATTK "💣 ScavTrap " BOLD << _name;
	std::cout << ATTK " inflits " RED << _attack_dmg << ATTK " damages to " BOLD;
	std::cout << target << ATTK ". 💣" RESET;
}

void ScavTrap::guardGate()
{
	if (not _hit_pts)
	{
		std::cout << RED "📛 ScavTrap " BOLD << _name << RED " is already dead ! 📛" RESET;
		return;
	}

	std::cout << GATEKEEP "🛡️ ScavTrap " BOLD << _name << GATEKEEP " enters Gatekeeper mode. 🛡️" RESET;
}