/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:27:26 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/10 17:45:55 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string Weapon::getType(void) const
{
	return (_type);
}

void	Weapon::setType(std::string newType)
{
	_type = newType;
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

Weapon::~Weapon(void)
{
}