#ifndef ITER_HPP
# define ITER_HPP

template <typename T>
void	iter(T* array, const int N, void (*f)(T&))
{
	for (int i = 0; i < N; i++)
		f(array[i]);
}

template <typename T>
void	iter(const T* array, const int N, void (*f)(const T&))
{
	for (int i = 0; i < N; i++)
		f(array[i]);
}

#endif