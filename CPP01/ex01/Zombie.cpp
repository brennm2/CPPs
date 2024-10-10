/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:11:48 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/10 12:40:00 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << green << _name << reset << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}


Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
	std::cout << green << this->_name << red <<" killed!\n" << reset ;
}

