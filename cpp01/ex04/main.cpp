#include <fstream>
#include <iostream>

std::string search_and_replace( const std::string &s, const std::string& s1, const std::string &s2 )
{
	if (s.empty() or s1.empty())
		return (s);

	std::string				res;
	std::string::size_type	found;
	std::string::size_type	pos = 0;

	while ((found = s.find(s1, pos)) != std::string::npos)
	{
		res.append(s, pos, found - pos);
		res.append(s2);
		pos = found + s1.size();
	}

	res.append(s, pos);

	return (res);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "\e[31;1m🈲 Usage error: " << argv[0] << " <filename> <to search> <replace by> 🈲\e[0m\n";
		return (1);
	}

	std::ofstream	replace;
	std::ifstream	file(argv[1]);
	if (not file)
	{
		std::cout << "\e[31;1m🈲 Error: failed to open " << argv[1] << " 🈲\e[0m\n";
		return (1);
	}

	std::string		out = std::string(argv[1]) + ".replace";
	replace.open(out.c_str());
	if (not replace.is_open())
	{
		file.close();
		std::cout << "\e[31;1m🈲 Error: failed to open " << out << " 🈲\e[0m\n";
		return (1);
	}

	std::string line;
	while (std::getline(file, line))
	{
		line = search_and_replace(line, argv[2], argv[3]);
		replace << line << '\n';
	}

	file.close();
	replace.close();
	std::cout << "\e[36;1m🫧 Replace file created successfully at " << out << " 🫧\e[0m\n";
	return (0);
}
