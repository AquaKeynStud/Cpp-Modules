#include <list>
#include <deque>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
	try
	{
		/* -----===== VECTOR =====----- */
		std::vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);

		std::vector<int>::iterator itv = easyfind(v, 1);
		std::cout << "Vector trouvé: " << *itv << std::endl;

		/* -----===== LIST =====----- */
		std::list<int> l;
		l.push_back(10);
		l.push_back(20);
		l.push_back(30);

		std::list<int>::iterator itl = easyfind(l, 20);
		std::cout << "List trouvé: " << *itl << std::endl;

		/* -----===== DEQUE =====----- */
		std::deque<int> d;
		d.push_back(100);
		d.push_back(200);
		d.push_back(300);

		std::deque<int>::iterator itd = easyfind(d, 300);
		std::cout << "Deque trouvé: " << *itd << std::endl;

		/* -----===== TEST EXCEPTION =====----- */
		easyfind(v, 42);
	}
	catch (const std::exception& e)
	{
		std::cout << "\e[1;31mCode ran into an exception !\e[0m" << std::endl;
	}

	return (0);
}
