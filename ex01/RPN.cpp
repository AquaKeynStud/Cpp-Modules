#include "RPN.hpp"

using std::cout;
using std::stack;
using std::string;

typedef string::iterator index;

static void	add_nbr(stack<int>& buffer, int nbr)
{
	buffer.push(nbr);
}

static bool	is_operator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

static int	get_top(stack<int>& buffer)
{
	int	top = buffer.top();
	buffer.pop();
	return (top);
}

static void	handle_operation(stack<int>& buffer, char op)
{
	int second = get_top(buffer);
	int	first = get_top(buffer);

	if (op == '/' && second == 0)
		throw std::runtime_error("Division by 0");

	switch (op)
	{
		case '+':
			return (add_nbr(buffer, first + second));
		case '-':
			return (add_nbr(buffer, first - second));
		case '*':
			return (add_nbr(buffer, first * second));
		case '/':
			return (add_nbr(buffer, first / second));
		default:
			return;
	}
}

void	handle_expression(string exp)
{
	stack<int>	buffer;

	for (index it = exp.begin(); it != exp.end(); it++)
	{
		if (*it == ' ')
			continue;
		else if (isdigit(*it))
			add_nbr(buffer, *it - '0');
		else if (is_operator(*it) && buffer.size() >= 2)
			handle_operation(buffer, *it);
		else
			throw std::runtime_error("Error");
	}

	if (buffer.size() != 1)
		throw std::runtime_error("Error");
	cout << buffer.top() << "\n";
	return;
}
