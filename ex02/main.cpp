#include <cstdlib>
#include <iostream>
#include "Base.hpp"

#define	BOLD	"\e[1m"
#define	RESET	"\e[0m\n"

using std::cout;

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main()
{
	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		Base* obj = generate();

		identify(obj);
		identify(*obj);

		delete obj;

		cout << "\n━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n\n";
	}

	return (0);
}

Base* generate(void)
{
	int random = rand() % 3;

	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		cout << BOLD "Type: A" RESET;
	else if (dynamic_cast<B*>(p))
		cout << BOLD "Type: B" RESET;
	else if (dynamic_cast<C*>(p))
		cout << BOLD "Type: C" RESET;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout << BOLD "Type: A" RESET;
		return ;
	}
	catch(std::exception& e) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		cout << BOLD "Type: B" RESET;
		return ;
	}
	catch(std::exception& e) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		cout << BOLD "Type: C" RESET;
		return ;
	}
	catch(std::exception& e) {}
}
