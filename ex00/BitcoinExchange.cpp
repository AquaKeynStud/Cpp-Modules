#include "BitcoinExchange.hpp"

using std::map;
using std::cerr;
using std::cout;
using std::string;

/* -- DATABASE HANDLING -- */

static double	handle_values(const string& date, const string& value, bool	borned)
{
	char				c;
	double				rate;
	std::stringstream	ss(value);

	if (!check_date_format(date) || !(ss >> rate) || (ss >> c))
		throw std::runtime_error("bad input");
	if (borned && (rate < 0 || rate > 1000))
	{
		const char *msg = (rate < 0) ? "not a positive number." : "too large a number.";
		throw std::runtime_error(msg);
	}

	return (rate);
}

void	process_input(const string& filename, const map<string, double>& db)
{
	string			line;
	std::ifstream	file(filename.c_str());
	if (!file)
	{
		cerr << "Error: could not open file\n";
		return;
	}

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	pos = line.find(" | ");
		if (pos == string::npos)
		{
			cout << "Error: bad input => " << line << "\n";
			continue;
		}

		string	date = line.substr(0, pos);
		string	value = line.substr(pos + 3);

		try {
			double	rate = handle_values(date, value, true);
			std::map<string, double>::const_iterator it = db.lower_bound(date);
			
			if (it == db.end() || it->first != date)
			{
				if (it == db.begin())
				{
					cout << "Error: no data available for this date => " << date << "\n";
					continue;
				}
				--it;
			}

			double result = rate * it->second;
			cout << date << " => " << rate << " = " << result << "\n";
		} catch (const std::exception& e) {
			string	err = e.what();
			if (err == "bad input")
				cout << "Error: bad input => " << line << "\n";
			else
				cout << "Error: " << err << "\n";
		}
	}
}

bool	fill_database(map<string, double>& db)
{
	string			line;
	std::ifstream	file("data.csv");
	if (!file)
		return (cerr << "Error: could not open data.csv\n", false);

	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t	comma = line.find(',');
		if (comma == string::npos)
			return (cerr << "Error: Missing comma in database\n", false);

		string	date = line.substr(0, comma);
		string	value = line.substr(comma + 1);
		double	rate;

		try {
			rate = handle_values(date, value, false);
		} catch (const std::exception& e) {
			return (cerr << "Error: bad database\n", false);
		}

		db[date] = rate;
	}

	return (true);
}

/* -- UTILS -- */

bool	check_date_format(const string& date)
{
	if (date.size() != 10)
		return (false);

	for (int i = 0; i < 10; i++)
	{
		if (((i == 4 || i == 7) && date[i] == '-') || std::isdigit(date[i]))
			continue;
		return (false);
	}

	int	day = std::atoi(date.substr(8, 2).c_str());
	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};

	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
		days[1] = 29;

	return ((month >= 1 && month <= 12) && (day >= 1 && day <= days[month - 1]));
}
