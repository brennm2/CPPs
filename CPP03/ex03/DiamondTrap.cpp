/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:07:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/24 14:19:15 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hi, my name is: " << this->_Name << "\n";
	std::cout << "Hi, my real name is: " << ClapTrap::_Name << "\n";
}


DiamondTrap::DiamondTrap()
	: ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << magenta << "DiamondTrap Default Constructor Called\n" << reset;
	this->ClapTrap::_Name = this->_Name + "_clap_name";
	this->_Hp = _frag_hp;
	this->_Energy = _scav_energy;
	this->_Damage = _frag_damage;
}

DiamondTrap::DiamondTrap(std::string NewName)
	: ClapTrap(NewName + "_clap_name"), ScavTrap(NewName), FragTrap(NewName)
{
	std::cout << magenta << "DiamondTrap Default String Constructor Called\n" << reset;
	this->_Name = NewName;
	this->_Hp = _frag_hp;
	this->_Energy = _scav_energy;
	this->_Damage = _frag_damage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << red << "DiamondTrap Destructor Called\n" << reset;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << cyan << "DiamondTrap Copy Constructor Called\n" << reset;
	this->_Name = copy._Name;
	this->_Hp = copy._Hp;
	this->_Damage = copy._Damage;
	this->_Energy = copy._Energy;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy)
{
	std::cout << cyan << "DiamondTrap Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_Name = copy._Name;
		this->_Hp = copy._Hp;
		this->_Damage = copy._Damage;
		this->_Energy = copy._Energy;
	}
	return (*this);
}