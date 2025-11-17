#include <cctype>
#include <string>
#include <iostream>

int main(int argc, char **argv)
{
	std::string		s;
	unsigned char	c;

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; i < argc; i++)
	{
		s = argv[i];

		for (std::string::size_type j = 0; j < s.size(); j++)
		{
			c = static_cast<unsigned char>(s[j]);
			s[j] = static_cast<char>(std::toupper(c));
		}

		std::cout << s;
	}

	std::cout << std::endl;
	return (0);
}
