/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:31:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/15 16:52:05 by bde-souz         ###   ########.fr       */
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
	//std::cout << magenta << "Default Constructor Called\n" << reset;
}

Fixed::Fixed(const int Number)
{
	//std::cout << magenta << "Int Constant Constructor Called\n" << reset;
	_integer = Number << _static_integer;
}

Fixed::Fixed(const float Number)
{
	//std::cout << magenta << "Float Constructor Called\n" << reset;
	_integer = static_cast<int>(roundf(Number * (1 << _static_integer)));
}

Fixed::Fixed(const Fixed &copy)
{
	//std::cout << cyan << "Copy Constructor Called\n" << reset;
	*this = copy;
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	//std::cout << cyan << "Copy Assignment Operator Called\n" << reset;
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
	//std::cout << red << "Destructor Called\n" << reset;
}


//New Ones
//Comparision Operators
bool Fixed::operator<(const Fixed &copy)
{
	return _integer < copy._integer;
}

bool Fixed::operator>(const Fixed &copy)
{
	return _integer > copy._integer;
}

bool Fixed::operator>=(const Fixed &copy)
{
	return _integer >= copy._integer;
}

bool Fixed::operator<=(const Fixed &copy)
{
	return _integer <= copy._integer;
}

bool Fixed::operator==(const Fixed &copy)
{
	return _integer == copy._integer;
}

bool Fixed::operator!=(const Fixed &copy)
{
	return _integer != copy._integer;
}


//Arithmetic Operators
Fixed Fixed::operator+(const Fixed &copy)
{
	return this->toFloat() + copy.toFloat();
}

Fixed Fixed::operator-(const Fixed &copy)
{
	return this->toFloat() - copy.toFloat();
}

Fixed Fixed::operator*(const Fixed &copy)
{
	return this->toFloat() * copy.toFloat();
}

Fixed Fixed::operator/(const Fixed &copy)
{
	return this->toFloat() / copy.toFloat();
}


//Increment/Decrement Operators
//++a
Fixed& Fixed::operator++()
{
	_integer++;
	return *this;
}

//--a
Fixed& Fixed::operator--()
{
	_integer--;
	return *this;
}
//a++
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);

	_integer++;
	return (temp);
}
//a--
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);

	_integer--;
	return (temp);
}

//Public Overloaded
Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a._integer < b._integer)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._integer < b._integer)
		return (a);
	else
		return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a._integer > b._integer)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._integer > b._integer)
		return (a);
	else
		return (b);
}










