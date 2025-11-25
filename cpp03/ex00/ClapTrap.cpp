#include <iostream>
#include "ClapTrap.hpp"

/* -- Constructors -- */
ClapTrap::ClapTrap(std::string name)
	:	_name(name),
		_hit_pts(10),
		_energy_pts(10),
		_attack_dmg(0)
{
	std::cout << GREEN << "🎍 ClapTrap ";
	std::cout << BOLD << _name;
	std::cout << GREEN << " created ! 🎍";
	std::cout << RESET;
}



ClapTrap::ClapTrap(const ClapTrap& toCopy)
	:	_name(toCopy.getName()),
		_hit_pts(toCopy.getHitPts()),
		_energy_pts(toCopy.getEnergyPts()),
		_attack_dmg(toCopy.getAttackDmg())
{
	std::cout << GREEN << "🎋 ClapTrap ";
	std::cout << BOLD << _name;
	std::cout << GREEN << " copied ! 🎋";
	std::cout << RESET;
}

/* -- Destructor -- */
ClapTrap::~ClapTrap()
{
	std::cout << RED << "🍁 ClapTrap ";
	std::cout << BOLD << _name;
	std::cout << RED << " destroyed ! 🍁";
	std::cout << RESET;
}

/* -- Assignment operator -- */
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (not (this == &other))
	{
		_name = other.getName();
		_hit_pts = other.getHitPts();
		_energy_pts = other.getEnergyPts();
		_attack_dmg = other.getAttackDmg();
	}

	return (*this);
}

/* -- Getters -- */
int ClapTrap::getHitPts() const { return (_hit_pts); }

int ClapTrap::getEnergyPts() const { return (_energy_pts); }

int ClapTrap::getAttackDmg() const { return (_attack_dmg); }

const std::string& ClapTrap::getName() const { return (_name); }

/* -- Methods -- */
void ClapTrap::takeDamage(unsigned int amount)
{
	if (not _energy_pts or not _hit_pts)
		return;

	std::cout << DMGS << "🧨 ClapTrap ";
	std::cout << BOLD << _name;
	std::cout << DMGS << " took ";
	std::cout << RED << amount;
	std::cout << DMGS << " damages. 🧨";
	std::cout << RESET;

	_energy_pts--;
	_hit_pts -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (not _energy_pts or not _hit_pts)
		return;

	std::cout << HEAL << "♻️ ClapTrap ";
	std::cout << BOLD << _name;
	std::cout << HEAL << " repaired itself from ";
	std::cout << RED << amount;
	std::cout << HEAL << " damages. ♻️";
	std::cout << RESET;

	_energy_pts--;
	_hit_pts += amount;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << ATTK << "💣 ClapTrap ";
	std::cout << BOLD << _name;
	std::cout << ATTK << " inflits ";
	std::cout << RED << _attack_dmg;
	std::cout << ATTK << " damages to ";
	std::cout << BOLD << target;
	std::cout << ATTK << ". 💣";
	std::cout << RESET;
}
