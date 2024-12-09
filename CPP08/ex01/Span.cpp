/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:06:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 18:51:23 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::addNumber(int number)
{
	if (this->_vec.size() < _N)
	{
		_vec.push_back(number);
		// this->_currentN++;
	}
	else
	{
		throw NoSpaceLeft();
	}
}

void Span::printVec(void)
{
	std::cout << "Size: " << this->_N << "\n";
	for(size_t i = 0; i < this->_vec.size(); i++)
	{
		std::cout << cyan << "Current Vec: " \
			<< green << this->_vec[i] << "\n" << reset;
	}
}


Span::Span(unsigned int number)
	: _N(number), _currentN(0)
{
	//std::cout << magenta << "Span Number Constructor Called\n" << reset;

}

Span::Span()
	: _N(0), _currentN(0)
{
	//std::cout << magenta << "Span Default Constructor Called\n" << reset;
}

Span::~Span()
{
	//std::cout << red << "Span Destructor Called\n" << reset;
}

Span::Span(const Span &copy)
{
	//std::cout << cyan << "Span Copy Constructor Called\n" << reset;
	this->_N = copy._N;
	this->_currentN = copy._currentN;
	this->_vec = copy._vec;
}

Span &Span::operator=(const Span &copy)
{
	//std::cout << cyan << "Span Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_N = copy._N;
		this->_currentN = copy._currentN;
		this->_vec = copy._vec;
	}
	return (*this);
}

const char* NoSpaceLeft::what() const throw()
{
	return "Error: No space left in the Container!";
}