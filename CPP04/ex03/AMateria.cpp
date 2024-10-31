/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:18:45 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/31 15:58:50 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

void AMateria::use(ICharacter& target)
{
	std::cout << cyan "Using generic spell on " << reset 
	<< red << target.getName() << reset << " !\n";
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

AMateria::AMateria(std::string const &type)
{
	// std::cout << magenta << "AMateria String Constructor Called\n" << reset;
	this->_type = type;
}

AMateria::AMateria()
{
	// std::cout << magenta << "AMateria Default Constructor Called\n" << reset;
	this->_type = "default";
}

AMateria::~AMateria()
{
	// std::cout << red << "AMateria Destructor Called\n" << reset;
}

AMateria::AMateria(const AMateria &copy)
{
	// std::cout << cyan << "AMateria Copy Constructor Called\n" << reset;
	this->_type = copy._type;
}

AMateria &AMateria::operator=(const AMateria &copy)
{
	// std::cout << cyan << "AMateria Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}