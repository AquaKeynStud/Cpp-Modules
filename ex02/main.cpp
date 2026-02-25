#include <list>
#include <iostream>
#include "MutantStack.hpp"

void	ListTests(void);
void	MutantStackTests(void);

int main()
{
	std::cout << "\e[1m |-----===== MUTANT STACK TESTS =====-----| \e[0m\n\n";
	MutantStackTests();
	std::cout << "\n\e[1m |-----===== LIST TESTS =====-----| \e[0m\n\n";
	ListTests();
	std::cout << "\n\e[1m |-----===== MY TESTS =====-----| \e[0m\n\n";

	MutantStack<int> a;
	MutantStack<int> b(a);

	a.push(1);
	a.push(2);
	a.push(3);
	
	MutantStack<int> c(a);

	std::cout << "Sizes: A=" << a.size() << ", B=" << b.size() << ", C=" << c.size() << "\n";

	MutantStack<int>::iterator it = c.begin();

	std::cout << "c[1]=" << *it++ << "\n";
	std::cout << "c[2]=" << *it++ << "\n";
	*it = 42;
	std::cout << "c[3]=" << *it << "\n";

	c.pop();

	std::cout << "C size: " << c.size() << "\n";

	b = c;

	std::cout << "B size: " << b.size() << "\n";

	MutantStack<int>::const_iterator cit = b.end();
	--cit;

	std::cout << (*cit == b.top() ? "True\n" : "False\n");
	std::cout << "Last element in B (top func): " << b.top() << "\n";
	std::cout << "Last element in B (cont_iter): " << *cit << "\n";

	return (0);
}

void	MutantStackTests(void)
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void	ListTests(void)
{
	std::list<int>	lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	//[...]
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(lst);
}
