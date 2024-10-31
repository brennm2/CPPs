/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:34:47 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/31 17:05:04 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"


void Cure::use(ICharacter& target)
{
	std::cout << yellow << "\n-------------------------\n|";
	std::cout << green " * heals " <<  red << target.getName()
	<< green << "'s wounds *";
	std::cout << yellow << "|\n-------------------------\n\n" << reset;
}

AMateria *Cure::clone() const
{
	return (new Cure);
}

Cure::Cure() : AMateria("cure")
{
	//std::cout << magenta << "Cure Default Constructor Called\n" << reset;
}

Cure::~Cure()
{
	//std::cout << red << "Cure Destructor Called\n" << reset;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	//std::cout << cyan << "Cure Copy Constructor Called\n" << reset;
	//this->_type = copy._type;
}

Cure &Cure::operator=(const Cure &copy)
{
	//std::cout << cyan << "Cure Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}