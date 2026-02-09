#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

using	std::string;

/* -- Class implementation -- */

Intern::Intern() { std::cout << NEW_INTERN "🫠 New Intern created 🫠" << RESET; }

Intern::Intern(const Intern& toCopy)
{ 
	(void)toCopy;
	std::cout << NEW_INTERN "🫠 New copy of Intern created 🫠" << RESET;
}

Intern::~Intern() { std::cout << NO_INTERN "💀 Intern destroyed 💀" << RESET; }

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return (*this);
}


/* -- Methods -- */
AForm* Intern::RobotomyRequest(const string& target) const
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::ShrubberyCreation(const string& target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::PresidentialPardon(const string& target) const
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const string& name, const string& target) const
{
	static const string names[3] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	static AForm* (Intern::* f[3])(const string&) const = {
		&Intern::RobotomyRequest,
		&Intern::ShrubberyCreation,
		&Intern::PresidentialPardon
	};

	for (int i = 0; i < 3; i++)
		if (name == names[i])
		{
			std::cout << WHITE "📑 Intern creates " << names[i] << ". 📑" RESET;
			return ((this->*f[i])(target));
		}
	std::cout << ERROR "📌 Form named " << name << "doesn't exist. 📌" RESET;
	return (NULL);
}
