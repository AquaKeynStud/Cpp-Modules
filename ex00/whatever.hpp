#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void	swap(T& n, T& m)
{
	T tmp = n;

	n = m;
	m = tmp;
}

template <typename T>
T		min(T n, T m)
{
	return (n < m ? n : m);
}

template <typename T>
T		max(T n, T m)
{
	return (n > m ? n : m);
}

#endif