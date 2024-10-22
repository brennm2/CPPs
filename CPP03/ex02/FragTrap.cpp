/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:09:24 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/22 19:37:28 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(std::string NewName) : ClapTrap(NewName)
{
	std::cout << magenta << "FragTrap Default Constructor Called\n" << reset;
	this->_Name = NewName;
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