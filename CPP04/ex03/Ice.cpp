/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:34:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/31 17:04:57 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

void Ice::use(ICharacter& target)
{	std::cout << yellow << "\n---------------------------------\n| ";
	std::cout << cyan "* shoots an ice bolt at " << reset 
	<< red << target.getName() << cyan << " * "; 
	std::cout << yellow << "|\n---------------------------------\n" << reset;
}

AMateria *Ice::clone() const
{
	return (new Ice);
}

Ice::Ice() : AMateria("ice")
{
	// std::cout << magenta << "Ice Default Constructor Called\n" << reset;
}

Ice::~Ice()
{
	//std::cout << red << "Ice Destructor Called\n" << reset;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	//std::cout << cyan << "Ice Copy Constructor Called\n" << reset;
	//this->_type = copy._type;
}

Ice &Ice::operator=(const Ice &copy)
{
	//std::cout << cyan << "Ice Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}