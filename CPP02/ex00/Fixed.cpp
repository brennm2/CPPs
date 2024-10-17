/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:31:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/17 11:00:02 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return(_integer);
}

void Fixed::setRawBits( int const raw )
{
	_integer = raw;
}


Fixed::Fixed() : _integer(0)
{
	std::cout << magenta << "Default Constructor Called\n" << reset;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << cyan << "Copy Constructor Called\n" << reset;
	_integer = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	std::cout << cyan << "Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		_integer = copy.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << red << "Destructor Called\n" << reset;
}


