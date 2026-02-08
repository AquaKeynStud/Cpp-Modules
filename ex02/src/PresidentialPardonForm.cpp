#include <iostream>
#include "PresidentialPardonForm.hpp"

/* -- Usings -- */
using std::cout;

/* -- Class -- */
PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("Random guy")
{
	cout << NEW_AFORM "🤵 New PresidentialPardonForm created with [" << _target << "] as target 🤵" RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	cout << NEW_AFORM "🤵 New PresidentialPardonForm created with [" << _target << "] as target 🤵" RESET;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& toCopy)
	: AForm("PresidentialPardonForm", 25, 5), _target(toCopy._target)
{
	cout << NEW_AFORM "🤵 New copy of a PresidentialPardonForm created 🤵" RESET;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << NO_AFORM "🫥 PresidentialPardonForm destroyed 🫥" RESET;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
		_target = other._target;

	return (*this);
}

bool PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!canExec(executor))
		return (false);

	cout << PRESIDENT << _target << " has been pardoned by Zaphod Beeblebrox 🫨" RESET;

	return (true);
}
