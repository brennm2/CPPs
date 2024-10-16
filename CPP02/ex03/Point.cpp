/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:20:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/16 14:09:46 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}

Point::Point() : _x(0.0f), _y(0.0f)
{
	//std::cout << magenta << "Default Constructor Called\n" << reset;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	//std::cout << magenta << "Const Constructor Called\n" << reset;
}

Point::Point(const Point &copy) :_x(copy._x), _y(copy._y)
{
	//std::cout << cyan << "Copy Constructor Called\n" << reset;
}

Point &Point::operator=(const Point &copy)
{
	//std::cout << cyan << "Copy Assignment Operator Called\n" << reset;
	
	if (this != &copy)
	{
		_x = copy._x;
		_y = copy._y;
	}
	return (*this);
}

Point::~Point()
{
	//std::cout << red << "Destructor Called\n" << reset;
}