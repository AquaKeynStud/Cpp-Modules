#include <iostream>
#include "Bureaucrat.hpp"

/* -- Usings -- */
using std::cout;

/* -- COLORS -- */
#define	CATEGORY	"\e[1;38;2;255;230;70m"

int main()
{
	std::cout << CATEGORY "🧪 TEST cpp05 - Bureaucrat 🧪\n" RESET;

	/* -- CONSTRUCTEUR OK -- */
	{
		try
		{
			Bureaucrat unknown;
			Bureaucrat boss("Boss", 1);
			Bureaucrat worker(unknown);
			worker = boss;

			cout << boss << RESET;
			cout << worker << RESET;
			cout << unknown << RESET;

			cout << CATEGORY "🔅 Rétrogradation" RESET;
			boss.demote();
			cout << "⬇ boss grade = " << boss.getGrade() << RESET;

			cout << CATEGORY "🔅 Promotion" RESET;
			boss.promote();
			cout << "⬆ boss grade = " << boss.getGrade() << RESET;
		}
		catch (std::exception& e)
		{
			cout << ERROR "❌ Exception inattendue: " << e.what() << RESET;
		}
	}

	/* -- CONSTRUCTEUR KO -- */
	cout << CATEGORY "\n🔅 Création invalide\n" RESET;

	{
		try
		{
			Bureaucrat lower("Lower", 151);
			(void)lower;
		}
		catch (const std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}

		try
		{
			Bureaucrat higher("Higher", 0);
			(void)higher;
		}
		catch (const std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}

		try
		{
			Bureaucrat other("Other", -10);
			(void)other;
		}
		catch(const std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}
	}


	/* -- LIMITE PROMOTION -- */
	cout << CATEGORY "\n🔅 Promotion limite\n" RESET;

	{
		Bureaucrat boss("Boss", 1);
		try
		{
			boss.promote();
		}
		catch (std::exception& e)
		{
			cout << ERROR "📛 Exception attrapée (comportement attendu): " << e.what() << RESET;
		}
	}

	cout << CATEGORY "\n🎉 Tous les tests sont passés !" << RESET;
	return (0);
}
