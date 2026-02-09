#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

/* -- COLORS -- */
#define ERROR       "\e[1;31m"
#define CATEGORY    "\e[1;38;2;255;180;70m"

using std::cout;

int main()
{
	cout << CATEGORY "━━━━━━━━━━━━ 🧪 TEST cpp05 ex02 - More Forms 🧪 ━━━━━━━━━━━━\n" RESET;

	Bureaucrat boss("Boss", 1);
	Bureaucrat stagiaire("Stagiaire", 140);

	RobotomyRequestForm dummy;
	ShrubberyCreationForm hill;
	PresidentialPardonForm random;
	
	std::srand(std::time(NULL));				// Injecting an arbitrary value as a seed

	cout << CATEGORY "\n━━━━━━━━━━━━ 🔅 ShrubberyCreationForm tests 🔅 ━━━━━━━━━━━━\n" RESET;

	hill.execute(boss);
	hill.beSigned(stagiaire);

	try
	{	
		hill.execute(stagiaire);
	}
	catch(const std::exception& e)
	{
		cout << ERROR "📛 Exception: " << e.what() << " 📛" RESET;
	}

	hill.execute(boss);

	cout << CATEGORY "\n━━━━━━━━━━━━ 🔅 RobotomyRequestForm tests 🔅 ━━━━━━━━━━━━\n" RESET;

	dummy.execute(boss);

	try
	{	
		dummy.beSigned(stagiaire);
	}
	catch(const std::exception& e)
	{
		cout << ERROR "📛 Exception: " << e.what() << " 📛" RESET;
	}

	dummy.beSigned(boss);

	try
	{	
		dummy.execute(stagiaire);
	}
	catch(const std::exception& e)
	{
		cout << ERROR "📛 Exception: " << e.what() << " 📛" RESET;
	}

	boss.executeForm(dummy);

	cout << CATEGORY "\n━━━━━━━━━━━━ 🔅 PresidentialPardonForm tests 🔅 ━━━━━━━━━━━━\n" RESET;

	boss.executeForm(random);

	try
	{	
		random.beSigned(stagiaire);
	}
	catch(const std::exception& e)
	{
		cout << ERROR "📛 Exception: " << e.what() << " 📛" RESET;
	}

	random.beSigned(boss);

	try
	{	
		stagiaire.executeForm(random);
	}
	catch(const std::exception& e)
	{
		cout << ERROR "📛 Exception: " << e.what() << " 📛" RESET;
	}

	try
	{	
		random.execute(stagiaire);
	}
	catch(const std::exception& e)
	{
		cout << ERROR "📛 Exception: " << e.what() << " 📛" RESET;
	}

	random.execute(boss);

	cout << CATEGORY "\n━━━━━━━━━━━━ 🔅 Destruction 🔅 ━━━━━━━━━━━━\n" RESET;

	return (0);
}
