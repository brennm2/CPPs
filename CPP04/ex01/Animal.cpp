/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:02:19 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/24 12:14:51 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

std::string Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << yellow << "*The sound of the Void*" << "\n" << reset;
}

Animal::Animal()
{
	std::cout << magenta << "Animal Default Constructor Called\n" << reset;
	this->_type = "default";
}

Animal::~Animal()
{
	std::cout << red << "Animal Destructor Called\n" << reset;
}

Animal::Animal(const Animal &copy)
{
	std::cout << cyan << "Animal Copy Constructor Called\n" << reset;
	this->_type = copy._type;
}

Animal &Animal::operator=(const Animal &copy)
{
	std::cout << cyan << "Animal Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}