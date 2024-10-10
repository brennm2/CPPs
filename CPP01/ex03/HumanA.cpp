/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:40:11 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/10 17:34:20 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_Weapon->getType() << "\n";
}

HumanA::HumanA(std::string Name, Weapon &start_weapon)
{
	_name = Name;
	_Weapon = &start_weapon;
}

HumanA::~HumanA()
{
}
