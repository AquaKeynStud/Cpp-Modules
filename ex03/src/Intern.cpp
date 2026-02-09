#include "Intern.hpp"

/* -- Constructors -- */
Intern::Intern() {}

Intern::Intern(const Intern& toCopy) {}

/* -- Destructor -- */
Intern::~Intern() {}

/* -- Assignement operator -- */
Intern& operator=(const Intern& other)
{
	return (*this);
}

AForm* makeForm(const std::string& name, const std::string& target) const
{
	static const std::string& names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	static const Intern::*f[3] = 
}