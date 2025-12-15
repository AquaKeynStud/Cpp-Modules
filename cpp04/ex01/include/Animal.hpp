#ifndef ANIMAL_HPP
# define ANIMAL_HPP

/* -- Includes -- */
#include <string>
#include "Brain.hpp"									// <- new

/* -- Colors -- */
#define	RED		"\e[38;2;255;170;150;1m"
#define	GREEN	"\e[38;2;160;255;200;1m"
#define	SOUND	"\e[38;2;230;150;50;1m"

#define	RESET	"\e[0m"

/* -- Class -- */
class Animal
{
protected:
	std::string	type;

public:
// Constructors //
	Animal();
	Animal(const std::string& type);
	Animal(const Animal& toCopy);

// Destructor //
	virtual ~Animal();

// Assignment operator //
	Animal&	operator=(const	Animal& other);

// Getters //
	const std::string&	getType(void) const;

// Methods //
	virtual void	makeSound(void) const;
};

#endif