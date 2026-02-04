#include <iostream>
#include "Bureaucrat.hpp"

/* -- COLORS -- */
#define	ERROR		"\e[1;31m"
#define	CATEGORY	"\e[1;38;2;255;230;70m"

int main()
{
	std::cout << CATEGORY "🧪 TEST cpp05 - Bureaucrat 🧪\n" RESET;

	/* -- CONSTRUCTEUR OK -- */
	try
	{
		Bureaucrat unknown;
		Bureaucrat boss("Boss", 1);
		Bureaucrat worker(unknown);
		worker = boss;

		std::cout << "✔ " << boss.getName() << " | grade " << boss.getGrade() << RESET;
		std::cout << "✔ " << worker.getName() << " | grade " << worker.getGrade() << RESET;
		std::cout << "✔ " << unknown.getName() << " | grade " << unknown.getGrade() << RESET;

		std::cout << CATEGORY << "▶ Rétrogradation" << RESET;
		boss.demote();
		std::cout << "⬇ boss grade = " << boss.getGrade() << RESET;

		std::cout << CATEGORY << "▶ Promotion" << RESET;
		boss.promote();
		std::cout << "⬆ boss grade = " << boss.getGrade() << RESET;
	}
	catch (std::exception& e)
	{
		std::cout << ERROR "❌ Exception inattendue: " << e.what() << RESET;
	}

	/* -- CONSTRUCTEUR KO -- */
	std::cout << CATEGORY "\n▶ Création invalide\n" RESET;

	try
	{
		Bureaucrat lower("Lower", 151);
		(void)lower;
	}
	catch (const std::exception& e)
	{
		std::cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
	}

	try
	{
		Bureaucrat higher("Higher", 0);
		(void)higher;
	}
	catch (const std::exception& e)
	{
		std::cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
	}

	try
	{
		Bureaucrat other("Other", -10);
		(void)other;
	}
	catch(const std::exception& e)
	{
		std::cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
	}


	/* -- LIMITE PROMOTION -- */
	std::cout << CATEGORY << "\n▶ Promotion limite\n" << RESET;

	Bureaucrat boss("Boss", 1);
	try
	{
		boss.promote();
	}
	catch (std::exception& e)
	{
		std::cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
	}

	std::cout << CATEGORY "\n🎉 Tous les tests sont passés !" << RESET;
	return (0);
}
