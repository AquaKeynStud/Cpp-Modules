#ifndef WRONGWrongCAT_HPP
# define WRONGWrongCAT_HPP

/* -- Includes -- */
#include <string>
#include "WrongAnimal.hpp"

/* -- Class -- */
class WrongCat : public WrongAnimal
{
public:
// Constructors //
	WrongCat();
	WrongCat(const WrongCat& toCopy);

// Destructor //
	~WrongCat();

// Assignment operator //
	WrongCat&	operator=(const	WrongCat& other);

// Getters //
	const std::string&	getType(void) const;
};

#endif