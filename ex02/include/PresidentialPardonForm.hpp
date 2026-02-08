#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

/* -- Includes -- */
#include "AForm.hpp"

/* -- Colors -- */
#define	PRESIDENT	"\e[1;38;2;255;150;225m"

/* -- Class -- */
class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& toCopy);

	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	bool	execute(const Bureaucrat& executor) const;
};

#endif
