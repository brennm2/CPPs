/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:18:48 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 17:14:29 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


std::string WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << cyan << "*Intense Wrong Animal sound!*" << "\n" << reset;
}

WrongAnimal::WrongAnimal()
{
	std::cout << magenta << "WrongAnimal Default Constructor Called\n" << reset;
	this->_type = "default";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << red << "WrongAnimal Destructor Called\n" << reset;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << cyan << "WrongAnimal Copy Constructor Called\n" << reset;
	this->_type = copy._type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
	std::cout << cyan << "WrongAnimal Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}