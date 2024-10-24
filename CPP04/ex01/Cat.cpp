/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:08:49 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/24 12:14:13 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::makeSound(void) const
{
	std::cout << green << "*Meow Meow!*" << "\n" << reset;
}

Cat::Cat()
{
	std::cout << magenta << "Cat Default Constructor Called\n" << reset;
	this->_type = "Cat";
}

Cat::~Cat()
{
	std::cout << red << "Cat Destructor Called\n" << reset;
}

Cat::Cat(const Cat &copy)
{
	std::cout << cyan << "Cat Copy Constructor Called\n" << reset;
	this->_type = copy._type;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << cyan << "Cat Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}