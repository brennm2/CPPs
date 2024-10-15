/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:31:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/15 14:15:06 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int Fixed::getRawBits( void ) const
{
	return(_integer);
}

void Fixed::setRawBits( int const raw )
{
	_integer = raw;
}


float Fixed::toFloat( void ) const
{
	return static_cast<float> (_integer) / (1 << _static_integer);
}

int Fixed::toInt( void ) const
{
	return _integer >> _static_integer;
}


Fixed::Fixed() : _integer(0)
{
	std::cout << magenta << "Default Constructor Called\n" << reset;
}

Fixed::Fixed(const int Number)
{
	std::cout << magenta << "Int Constant Constructor Called\n" << reset;
	_integer = Number << _static_integer;
}

Fixed::Fixed(const float Number)
{
	std::cout << magenta << "Float Constructor Called\n" << reset;
	_integer = static_cast<int>(roundf(Number * (1 << _static_integer)));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << cyan << "Copy Constructor Called\n" << reset;
	*this = copy;
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

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed()
{
	std::cout << red << "Destructor Called\n" << reset;
}


