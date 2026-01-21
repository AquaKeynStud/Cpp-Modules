#include <iostream>
#include "ClapTrap.hpp"

/* -- Constructors -- */
ClapTrap::ClapTrap()
	:	_name("Clap"),
		_hit_pts(10),
		_energy_pts(10),
		_attack_dmg(0)
{
	std::cout << GREEN "🎍 ClapTrap " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

ClapTrap::ClapTrap(const std::string& name)
	:	_name(name),
		_hit_pts(10),
		_energy_pts(10),
		_attack_dmg(0)
{
	std::cout << GREEN "🎍 ClapTrap " BOLD << _name;
	std::cout << GREEN " created ! 🎍" RESET;
}

ClapTrap::ClapTrap(const ClapTrap& toCopy)
	:	_name(toCopy._name),
		_hit_pts(toCopy._hit_pts),
		_energy_pts(toCopy._energy_pts),
		_attack_dmg(toCopy._attack_dmg)
{
	std::cout << GREEN "🎋 ClapTrap " BOLD;
	std::cout << _name << GREEN " copied ! 🎋" RESET;
}

/* -- Destructor -- */
ClapTrap::~ClapTrap()
{
	std::cout << RED "🍁 ClapTrap " BOLD << _name << RED " destroyed ! 🍁" RESET;
}

/* -- Assignment operator -- */
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit_pts = other._hit_pts;
		_energy_pts = other._energy_pts;
		_attack_dmg = other._attack_dmg;
	}

	return (*this);
}

/* -- Methods -- */
void ClapTrap::takeDamage(unsigned int amount)
{
	if (not _hit_pts)
	{
		std::cout << RED "📛 ClapTrap " BOLD << _name << RED " is already dead ! 📛" RESET;
		return;
	}

	std::cout << DMGS "🧨 ClapTrap " BOLD << _name;
	std::cout << DMGS " took " RED << amount << DMGS << " damages. 🧨" RESET;

	if (amount > _hit_pts)
		amount = _hit_pts;
	_hit_pts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (not _hit_pts or not _energy_pts)
	{
		std::cout << RED "📛 ClapTrap " BOLD << _name << RED;
		std::cout << (_hit_pts ? " is exhausted ! 📛" : " is dead ! 📛") << RESET;
		return;
	}

	std::cout << HEAL "♻️ ClapTrap " BOLD << _name;
	std::cout << HEAL " repaired itself from " RED << amount << HEAL " damages. ♻️" RESET;

	_energy_pts--;
	_hit_pts += amount;
}

void ClapTrap::attack(const std::string& target)
{
	if (not _hit_pts or not _energy_pts)
	{
		std::cout << RED "📛 ClapTrap " BOLD << _name << RED;
		std::cout << (_hit_pts ? " is exhausted ! 📛" : " is dead ! 📛") << RESET;
		return;
	}

	_energy_pts--;

	std::cout << ATTK "💣 ClapTrap " BOLD << _name;
	std::cout << ATTK " inflits " RED << _attack_dmg << ATTK " damages to " BOLD;
	std::cout << target << ATTK ". 💣" RESET;
}
