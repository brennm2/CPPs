/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:08:49 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 17:52:26 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

void	Cat::think(unsigned int number)
{
	this->_brain->speakIdeas(this->_type, number);
}

void	Cat::setIdeias(unsigned int index, std::string idea)
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

void	Cat::makeSound(void) const
{
	std::cout << green << "*Meow Meow!*" << "\n" << reset;
}

Cat::Cat() : Animal()
{
	std::cout << magenta << "Cat Default Constructor Called\n" << reset;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << red << "Cat Destructor Called\n" << reset;
	delete this->_brain;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
	std::cout << cyan << "Cat Copy Constructor Called\n" << reset;
	this->_type = copy._type;
	this->_brain = new Brain(*copy._brain);
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << cyan << "Cat Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		Animal::operator=(copy);
		delete this->_brain;
		this->_type = copy._type;
		this->_brain = new Brain(*copy._brain);
	}
	return (*this);
}