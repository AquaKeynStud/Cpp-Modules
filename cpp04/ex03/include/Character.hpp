#ifndef CHARACTER_HPP
# define CHARACTER_HPP

/* -- Includes -- */
#include "AMateria.hpp"
#include "ICharacter.hpp"

/* -- Colors -- */
#define CREATE	"\e[2;38;230;180;255;1m"
#define DESTROY	"\e[2;38;140;60;170;1m"

/* -- Class -- */
class Character : public ICharacter
{

public:
// Constructors //
	Character(const std::string& name);
	Character(const Character& toCopy);

// Destructor //
	~Character();

// Assignment operator //
	Character&	operator=(const Character& other);

// Getter //
	const std::string& getName() const;

// Methods //
	void		unequip(int idx);
	void		equip(AMateria* m);
	void		use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inventory[4];

};

#endif