#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

/* -- Includes -- */
#include "AForm.hpp"

/* -- Colors -- */
#define	NEW_FILE	"\e[1;38;2;40;100;200m"

/* -- Class -- */
class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& toCopy);

	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	bool	execute(const Bureaucrat& executor) const;
};

#endif
