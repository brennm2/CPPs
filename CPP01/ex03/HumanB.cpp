/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:50:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/10 17:22:43 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack(void)
{
	if (_Weapon == NULL)
		std::cout << this->_name << " has no weapon, using bare hands!\n";
	else
		std::cout << this->_name << " attacks with their " << this->_Weapon->getType() << "\n";
}

void	HumanB::setWeapon(Weapon &start_weapon)
{
	_Weapon = &start_weapon;
}


HumanB::HumanB(std::string Name, Weapon &start_weapon)
{
	_name = Name;
	_Weapon = &start_weapon;
}

HumanB::HumanB(std::string Name)
{
	_name = Name;
	_Weapon = NULL;
}
