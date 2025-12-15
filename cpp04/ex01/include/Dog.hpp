#ifndef DOG_HPP
# define DOG_HPP

/* -- Includes -- */
#include <string>
#include "Animal.hpp"

/* -- Class -- */
class Dog : public Animal
{
private:											// <- new
	Brain*	_brain;									// <- new

public:
// Constructors //
	Dog();
	Dog(const Dog& toCopy);

// Destructor //
	~Dog();

// Assignment operator //
	Dog&	operator=(const	Dog& other);

// Getters //
	const std::string&	getType(void) const;

// Methods //
	Brain&			getBrain(void);					// <- new
	void			makeSound(void) const;
};

#endif