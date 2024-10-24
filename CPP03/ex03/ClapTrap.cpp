/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:25 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/24 13:47:50 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


std::string ClapTrap::getName(void)
{
	return (this->_Name);
}

unsigned int ClapTrap::getEnergy(void)
{
	return (this->_Energy);
}

unsigned int ClapTrap::getDamage(void)
{
	return (this->_Damage);
}

unsigned int ClapTrap::getHp(void)
{
	return (this->_Hp);
}


void	ClapTrap::attack(const std::string& target)
{
	if (this->_Hp <= 0)
	{
		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " is dead. It cannot attack :c\n";
	}
	else if (this->_Energy <= 0)
	{
		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " cannot attack. It has no energy left!\n";
	}
	else
	{
		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " attacks " << green << target << reset;
		std::cout << " causing " << red << this->_Damage << reset << " poits of damage!\n";
		this->_Energy -= 1;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_Hp <= 0)
	{
		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " is already dead, stop that!\n";
	}
	else
	{
		int temp_hp = this->_Hp;

		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " has taken " << red << amount << reset << " damage!\n";

		temp_hp -= amount;
		if (temp_hp < 0)
			temp_hp = 0;
		this->_Hp = temp_hp;
		if (this->_Hp <= 0)
			std::cout << "The ClapTrap " << red << this->_Name << reset << " is now dead!" << "\n";
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_Hp <= 0)
	{
		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " is already dead, stop that!\n";
	}
	else if (this->_Energy <= 0)
	{
		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " cannot be repaired. It has no energy left!\n";
	}
	else
	{
		std::cout << "The ClapTrap " << blue << this->_Name << reset;
		std::cout << " has repaired " << red << amount << reset << " of HP!\n";
		this->_Hp += amount;
		this->_Energy -= 1;
	}
}


ClapTrap::ClapTrap()
	: _Name("default"), _Hp(10), _Energy(10), _Damage(0)
{
	std::cout << magenta << "Default Constructor Called\n" << reset;
}

ClapTrap::ClapTrap(std::string Name)
	: _Hp(10), _Energy(10), _Damage(0)
{
	std::cout << magenta << "ClapTrap Default String Constructor Called\n" << reset;
	_Name = Name;
}

ClapTrap::~ClapTrap()
{
	std::cout << red << "ClapTrap Destructor Called\n" << reset;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << cyan << "ClapTrap Copy Constructor Called\n" << reset;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Energy = copy._Energy;
	this->_Damage = copy._Damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << cyan << "ClapTrap Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_Name = copy._Name;
		this->_Hp = copy._Hp;
		this->_Energy = copy._Energy;
		this->_Damage = copy._Damage;
	}
	return (*this);
}