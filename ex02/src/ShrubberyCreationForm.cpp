#include <fstream>
#include <iostream>
#include "ShrubberyCreationForm.hpp"

/* -- Usings -- */
using std::cout;

/* -- Class -- */
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("Home")
{
	cout << NEW_AFORM "🌳 New ShrubberyCreationForm created with [" << _target << "] as target 🌳" RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	cout << NEW_AFORM "🌳 New ShrubberyCreationForm created with [" << _target << "] as target 🌳" RESET;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& toCopy)
	: AForm("ShrubberyCreationForm", 145, 137), _target(toCopy._target)
{
	cout << NEW_AFORM "🌳 New copy of a ShrubberyCreationForm created 🌳" RESET;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << NO_AFORM "🪾  ShrubberyCreationForm destroyed 🪾" RESET;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		_target = other._target;

	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (not getSigned())
	{
		cout << ERROR "🔖 The form must be signed to be executed 🔖" RESET;
		return ;
	}
	else if (executor.getGrade() > getExecGrade())
		throw GradeTooLowException(executor.getGrade());

	std::ofstream file((_target + "_shrubbery").c_str());
	static const char* s_forest =
		" ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n"
		"/|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
		"/|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
		"/|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n";

	file << s_forest;

	file.close();
	cout << NEW_FILE << _target + "_shrubbery file created ! 📫" RESET;
	return ;
}
