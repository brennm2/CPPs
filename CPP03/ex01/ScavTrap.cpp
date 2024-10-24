/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 12:06:18 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/24 13:31:34 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

void ScavTrap::attack(const std::string& target)
{
	if (this->_Hp <= 0)
	{
		std::cout << "The ScavTrap " << blue << this->_Name << reset;
		std::cout << " is dead. It cannot attack :c\n";
	}
	else if (this->_Energy <= 0)
	{
		std::cout << "The ScavTrap " << blue << this->_Name << reset;
		std::cout << " cannot attack. It has no energy left!\n";
	}
	else
	{
		std::cout << "The ScavTrap " << blue << this->_Name << reset;
		std::cout << " attacks " << green << target << reset;
		std::cout << " causing " << red << this->_Damage << reset << " poits of damage!\n";
		this->_Energy -= 1;
	}
}

void ScavTrap::guardGate(void)
{
	if (this->_Hp <= 0)
	{
		std::cout << "The ScavTrap " << yellow << this->_Name << reset << " is dead, it cannot change Guard Gate mode!\n";
		return ;
	}
	if (_guardState == false)
	{
		this->_guardState = true;
		std::cout << "The ScavTrap "<< yellow << this->_Name << reset << " is now on Guard Gate mode!\n";
	}
	else
	{
		this->_guardState = false;
		std::cout << "The ScavTrap "<< yellow << this->_Name << reset << " is now out of Guard Gate mode!\n";
	}
}


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << magenta << "ScavTrap Default Constructor Called\n" << reset;
	this->_Hp = 100;
	this->_Energy = 50;
	this->_Damage = 20;
	this->_guardState = false;
}

ScavTrap::ScavTrap(std::string NewName) : ClapTrap(NewName)
{
	std::cout << magenta << "ScavTrap Default String Constructor Called\n" << reset;
	this->_Hp = 100;
	this->_Energy = 50;
	this->_Damage = 20;
	this->_guardState = false;
}

ScavTrap::~ScavTrap()
{
	std::cout << red << "ScavTrap Destructor Called\n" << reset;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << cyan << "ScavTrap Copy Constructor Called\n" << reset;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Energy = copy._Energy;
	this->_Damage = copy._Damage;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	std::cout << cyan << "ScavTrap Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
		{
			this->_Name = copy._Name;
			this->_Hp = copy._Hp;
			this->_Energy = copy._Energy;
			this->_Damage = copy._Damage;
		}
	return (*this);
}