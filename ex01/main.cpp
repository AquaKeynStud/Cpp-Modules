#include <string>
#include <iostream>
#include "iter.hpp"

using std::cout;
using std::string;

template <class T>
void	add(T& n);

template <class T>
void	printAddrValue(const T& value);

template <class T>
void	printArray(const T* array, const int N);

int main()
{
	{
		int a[5] = {1, 2, 3, 4, 5};

		printArray(a, 5);
		iter(a, 5, &add);
		printArray(a, 5);
	}

	cout << std::endl;

	{
		const std::string s[6] = {"a", "b", "c", "d", "e", "f"};

		printArray(s, 6);
		iter(s, 6, &printAddrValue);
		printArray(s, 6);
	}

	cout << std::endl;

	{
		string* s = new string[5];
		s[0] = "A";
		s[1] = "B";
		s[2] = "C";
		s[3] = "D";
		s[4] = "E";

		printArray(s, 5);
		iter(s, 5, &printAddrValue);
		printArray(s, 5);

		delete[] s;
	}

	cout << std::endl;

	{
		char s[6] = {'a', 'b', 'c', 'd', 'e', 'f'};

		printArray(s, 6);
		iter(s, 6, &add);
		iter(s, 6, &add);
		printArray(s, 6);
	}
	
	return (0);
}

/* -- Other functions -- */

template <typename T>
void printArray(const T* array, const int N)
{
	cout << "[";
	for (int i = 0; i < N; i++)
	{
		cout << array[i];
		if (i != (N - 1))
			cout << ", ";
	}
	cout << "]\n";
}

template <typename T>
void	add(T& n) { n += 1; }

template <typename T>
void	printAddrValue(const T& value)
{
	cout << value << ": " << &value << std::endl;
}
