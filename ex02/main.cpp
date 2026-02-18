#include <string>
#include <iostream>
#include "Array.hpp"

using std::cout;
using std::string;

template <typename T>
void print(const Array<T>& tab, unsigned int size);

int main()
{
	Array<string>	a;
	Array<int>		b(5);

	for (int i = 0; i < 5; i++)
		b[i] = i;

	cout << "A size: " << a.size() << "\n";
	cout << "B size: " << b.size() << "\n";

	cout << "A vaut: "; print(a, 2);
	cout << "B vaut: "; print(b, 5);

	cout << "\n|-----======== DEEP COPY TEST ========-----|\n\n";

	{
		Array<int> c(b);
		
		for (int i = 0; i < 5; i++)
			c[i] = 1000 * i;

		cout << "B vaut: "; print(b, 5);
		cout << "C vaut: "; print(c, 5);
		b = c;
	}

	cout << "Nouveaux B après destruction de C: "; print(b, 5);

	cout << "\n\n";

	return (0);
}

template <typename T>
void print(const Array<T>& tab, unsigned int size)
{
    cout << "[";

    for (unsigned int i = 0; i < size; i++)
    {
        try
        {
            cout << tab[i];
        }
        catch (const std::exception& e)
        {
            cout << "\e[1;31m" << e.what() << "\e[0m\n";
			return ;
        }

        if (i + 1 < size)
            cout << ", ";
    }

    cout << "]\n";
}
