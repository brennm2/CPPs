/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:15:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/23 18:56:57 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

std::string Dog::getType(void)
{
	return (this->_type);
}

void	Dog::makeSound(void)
{
	std::cout << blue << "Bark Bark!" << "\n" << reset;
}

Dog::Dog() : Animal()
{
	std::cout << magenta << "Dog Default Constructor Called\n" << reset;
	this->_type = "Dog";
}

// Dog::Dog(const std::string &newType)
// {
// 	std::cout << magenta << "Dog Default Type Constructor Called\n" << reset;
// 	this->_type = newType;
// }

Dog::~Dog()
{
	std::cout << red << "Dog Destructor Called\n" << reset;
}

Dog::Dog(const Dog &copy)
{
	std::cout << cyan << "Dog Copy Constructor Called\n" << reset;
	this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << cyan << "Dog Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}