#ifndef INTERN_HPP
# define INTERN_HPP

/* -- Includes -- */
#include <string>
#include "AForm.hpp"

/* -- Colors -- */
#define	NEW_INTERN	"\e[1;38;2;;;m"
#define	NO_INTERN	"\e[1;38;2;;;m"

/* -- Class -- */
class	Intern
{
public:
	Intern();
	Intern(const Intern& toCopy);

	~Intern();

	Intern&	operator=(const Intern& other);

	AForm*	makeForm(const std::string& name, const std::string& target) const;
};

#endif
