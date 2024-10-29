/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:27:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 17:35:40 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <string>
#include <sstream>


void	Brain::createIdeas(void)
{
	std::cout << yellow << "Creating ideas" << "\n" << reset;

	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = "Vague idea";
	}
}

void	Brain::speakIdeas(std::string type, unsigned int number)
{
	if (number > 100)
		number = 100;
	for (unsigned int i = 0; i < number; i++)
	{
		std::cout << yellow << "Idea number: " << i + 1 << ", from "
		<< cyan << type << yellow << " "
		<< ": " << this->_ideas[i] << "\n" << reset;
	}
}

void	Brain::placeIdeias(unsigned int index, std::string idea)
{
	this->_ideas[index] = idea;
}

Brain::Brain()
{
	std::cout << magenta << "Brain Default Constructor Called\n" << reset;
	createIdeas();
}

Brain::~Brain()
{
	std::cout << red << "Brain Destructor Called\n" << reset;
}

Brain::Brain(const Brain &copy)
{
	std::cout << cyan << "Brain Copy Constructor Called\n" << reset;
	for (int i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
}

Brain &Brain::operator=(const Brain &copy)
{
	std::cout << cyan << "Brain Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = copy._ideas[i];
		}
	}
	return (*this);
}