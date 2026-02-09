#ifndef INTERN_HPP
# define INTERN_HPP

/* -- Includes -- */
#include "AForm.hpp"

/* -- Colors -- */
#define	WHITE		"\e[1m"
#define NEW_INTERN	"\e[1;38;2;255;225;125m"
#define	NO_INTERN	"\e[1;38;2;255;190;150m"

/* -- Class -- */
class Intern
{
private:
	AForm*	RobotomyRequest(const std::string& target) const;
	AForm*	ShrubberyCreation(const std::string& target) const;
	AForm*	PresidentialPardon(const std::string& target) const;

public:
	Intern();
	Intern(const Intern& toCopy);

	~Intern();

	Intern& operator=(const Intern& other);

	AForm*	makeForm(const std::string& name, const std::string& target) const;
};

#endif
