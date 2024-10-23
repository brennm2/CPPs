/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:09:24 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/23 14:52:56 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

void	FragTrap::highFivesGuys(void)
{
	if (this->_Hp <= 0)
		std::cout << yellow "Minion, I'm dead! I cannot do a high five right now..." << reset <<"\n";
	else
		std::cout << yellow << "Hello minion, give me a high five!" << reset <<  "\n";
}

FragTrap::FragTrap()
{
	std::cout << magenta << "FragTrap Default Constructor Called\n" << reset;
	this->_Name = "default";
	this->_Hp = 100;
	this->_Energy = 100;
	this->_Damage = 30;
}

FragTrap::FragTrap(std::string NewName) : ClapTrap(NewName)
{
	std::cout << magenta << "FragTrap Default String Constructor Called\n" << reset;
	this->_Hp = 100;
	this->_Energy = 100;
	this->_Damage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << red << "FragTrap Destructor Called\n" << reset;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << cyan << "FragTrap Copy Constructor Called\n" << reset;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Energy = copy._Energy;
	this->_Damage = copy._Damage;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
	std::cout << cyan << "FragTrap Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
			this->_Name = copy._Name;
			this->_Hp = copy._Hp;
			this->_Energy = copy._Energy;
			this->_Damage = copy._Damage;
	}
	return (*this);
}