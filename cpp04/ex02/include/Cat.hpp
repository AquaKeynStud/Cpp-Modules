#ifndef Cat_HPP
# define Cat_HPP

/* -- Includes -- */
#include <string>
#include "Animal.hpp"

/* -- Class -- */
class Cat : public Animal
{
private:
	Brain*	_brain;

public:
// Constructors //
	Cat();
	Cat(const Cat& toCopy);

// Destructor //
	~Cat();

// Assignment operator //
	Cat&	operator=(const	Cat& other);

// Getters //
	const std::string&	getType(void) const;

// Methods //
	Brain&				getBrain(void);
	virtual void		makeSound(void) const;
};

#endif