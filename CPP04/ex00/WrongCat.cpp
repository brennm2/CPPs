/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:23:10 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/24 12:25:21 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

void	WrongCat::makeSound(void) const
{
	std::cout << cyan << "*Wrong cat noise*" << "\n" << reset;
}

WrongCat::WrongCat()
{
	std::cout << magenta << "WrongCat Default Constructor Called\n" << reset;
	this->_type = "Wrong Cat";
}

WrongCat::~WrongCat()
{
	std::cout << red << "WrongCat Destructor Called\n" << reset;
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << cyan << "WrongCat Copy Constructor Called\n" << reset;
	this->_type = copy._type;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
	std::cout << cyan << "WrongCat Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_type = copy._type;
	}
	return (*this);
}