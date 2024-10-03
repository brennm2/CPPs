/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:41:48 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/03 18:44:05 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

void Account::makeDeposit(int deposit)
{
	(void)deposit;
	//std::cout << "makeDeposit\n";
}

bool Account::makeWithdrawal(int withdrawal)
{
	(void)withdrawal;
	//std::cout << "makeWithdrawal\n";
	return 0;
}

int Account::checkAmount( void )const
{
	//std::cout << "checkAmount\n";
	return 0;
}

void Account::displayStatus( void ) const
{
	//std::cout << "displayStatus\n";
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	//std::cout << "accounts: " << _nbAccounts << ";";
	// std::cout << "total: " << _totalAmount << ";";
	// std::cout << "deposits: " << _totalNbDeposits << ";";
	// std::cout << "deposits: " << _totalNbWithdrawals << ";";
	
	//std::cout << "displayAccountsInfos\n";
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
	std::cout << "] \n";
	
}

int Account::getNbWithdrawals( void )
{
	//std::cout << "getNbWithdrawals\n";
	return 0;
}

int Account::getNbDeposits( void )
{
	//std::cout << "getNbDeposits\n";
	
	return 0;
}

int Account::getTotalAmount( void )
{
	//std::cout << "getTotalAmount\n";
	return 0;
}

int Account::getNbAccounts( void )
{
//	std::cout << "getNbAccounts\n";
	return 0;
}

Account::Account(int initial_deposit)
{
	_accountIndex = 0;
	_amount = initial_deposit;
	
	//std::cout << "Account Constructor\n";
}
Account::~Account( void )
{
	//std::cout << "Account Destructor\n";
}