#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

/* -- Includes -- */
#include <string>

/* -- Class -- */
class WrongAnimal
{
protected:
	std::string	type;

public:
// Constructors //
	WrongAnimal();
	WrongAnimal(const std::string& type);
	WrongAnimal(const WrongAnimal& toCopy);

// Destructor //
	virtual ~WrongAnimal();

// Assignment operator //
	WrongAnimal&	operator=(const	WrongAnimal& other);

// Getters //
	const std::string&	getType(void) const;

// Methods //
	virtual void		makeSound(void) const;
};

#endif