/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:15:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 17:52:20 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

void	Dog::think(unsigned int number)
{
	this->_brain->speakIdeas(this->_type, number);
}

void	Dog::setIdeias(unsigned int index, std::string idea)
{
	index -= 1;
	if (index > 100)
	{
		std::cout << red <<"Out of idea index\n" << reset;
		return ;
	}
	else
	{
		this->_brain->placeIdeias(index, idea);
		return ;
	}
}

void	Dog::makeSound(void) const
{
	std::cout << blue << "*Bark Bark!*" << "\n" << reset;
}

Dog::Dog() : Animal()
{
	std::cout << magenta << "Dog Default Constructor Called\n" << reset;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << red << "Dog Destructor Called\n" << reset;
	delete this->_brain;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
	std::cout << cyan << "Dog Copy Constructor Called\n" << reset;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Dog &Dog::operator=(const Dog &copy)
{
	std::cout << cyan << "Dog Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete this->_brain;
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}