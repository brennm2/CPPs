/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:41:48 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/04 13:56:47 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account:: _nbAccounts = 0;
int Account:: _totalAmount = 0;
int Account:: _totalNbDeposits = 0;
int Account:: _totalNbWithdrawals = 0;


void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount +=deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	if (withdrawal >= checkAmount())
	{
		std::cout << "withdrawal:refused\n";
		return false;
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		_totalAmount -=withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << "amount:" << checkAmount() << ";";
		std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
	}
	return 0;
}

int Account::checkAmount( void )const
{
	return _amount;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << checkAmount() << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << "\n";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals << "\n";
}

void	Account::_displayTimestamp( void )
{
	time_t now = std::time(0);
	tm* local_Time = std::localtime(&now);
	
	std::cout << "[";
	std::cout << local_Time->tm_year + 1900;
	std::cout << std::setw(2) << (local_Time->tm_mon + 1);
	std::cout << std::setw(2) << std::setfill('0') << local_Time->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << local_Time->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << local_Time->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << local_Time->tm_sec;
	std::cout << "]";
	
}

int Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

int Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int Account::getTotalAmount( void )
{
	return _totalAmount;
}

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created\n";
}
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed\n";
}