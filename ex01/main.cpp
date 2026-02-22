#include "Span.hpp"
#include <iostream>

#define RESET	"\e[0m\n"
#define PURPLE	"\e[1;35m"

void addWrap(Span& span, int* values, const int size);

int	main()
{

	/* -----===== FIRST BLOC =====----- */
	std::cout << PURPLE "-----===== FIRST BLOC =====-----" RESET;
	{
		Span sp(12501);

		for (int i = 0; i < 25000; i += 2)
			sp.addNumber(i);

		sp.addNumber(3);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	/* -----===== SECOND BLOC =====----- */
	std::cout << PURPLE "-----===== SECOND BLOC =====-----" RESET;
	{
		Span a;
		Span b(2);

		int add[4] = {1, 2, 3};

		addWrap(a, add, 3);
		addWrap(b, add, 3);

		Span c(b);

		std::cout << "C 2nd element after copy: " << c[1] << "\n";	//	2

		c = a;

		addWrap(c, add, 3);
	}

	/* -----===== THIRD BLOC =====----- */
	std::cout << PURPLE "-----===== THIRD BLOC =====-----" RESET;
	{
		Span d(10);

		int add[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

		d.addNumbers(add + 1, add + 11);

		std::cout << d[0] << std::endl;
		std::cout << d[9] << std::endl;

		try {
			std::cout << d[10] << std::endl;
		} catch (const std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}

	return (0);
}

void addWrap(Span& span, int* values, const int size)
{
	for (int v = 0; v < size; v++)
	{
		try {
			span.addNumber(values[v]);
			std::cout << "Valeur ajoutée: " << values[v] << "\n";
		} catch (const std::exception& e) {
			std::cout << "\e[1;31m" << e.what() << "\e[0m\n";
			return ;
		}
	}
}
