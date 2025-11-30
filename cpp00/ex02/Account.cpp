#include <ctime>
#include <iostream>
#include "Account.hpp"

/* -- Initialisation des statiques -- */

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	:	_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_nbAccounts += 1;
	_totalAmount += _amount;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created\n";
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";closed\n";

	_nbAccounts -= 1;
	_totalAmount -= _amount;
	_totalNbDeposits -= _nbDeposits;
	_totalNbWithdrawals -= _nbWithdrawals;
}

int Account::getNbAccounts( void ) { return (_nbAccounts); }

int Account::getTotalAmount( void ) { return (_totalAmount); }

int Account::getNbDeposits( void ) { return (_totalNbDeposits); }

int Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void Account::makeDeposit( int deposit )
{
	_nbDeposits++;
	_amount += deposit;
}

bool Account::makeWithdrawal( int withdrawal )
{
	if (_amount < withdrawal)
		return (false);
	_nbWithdrawals++;
	_amount -= withdrawal;
	return (true);
}

int Account::checkAmount( void ) const { return (_amount); }

void Account::displayStatus( void ) const
{
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);		// Get the seconds since january 1st 1970
	std::tm *tm = std::localtime(&now);		// Conversion to a tm pointer by slicing in variables

	std::cout << "[";
	std::cout << tm->tm_year + 1900 << tm->tm_mon + 1 << tm->tm_mday;
	std::cout << "_";
	std::cout << tm->tm_hour << tm->tm_min << tm->tm_sec;
	std::cout << "] ";
}
