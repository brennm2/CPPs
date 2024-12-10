/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:06:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/10 18:09:20 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void Span::addRNumber(size_t amount)
{
	if (this->_N < amount)
		throw NoSpaceLeft();
	else
	{
		std::srand(std::time(0));
		int random_num = 0;
		for (size_t i = 0; i < this->_N; i++)
		{
			random_num = ::rand() % 20000;
			this->_vec.push_back(random_num);
		}
	}
}

int Span::shortestSpan()
{
	if (this->_N < 2)
		throw ToLowNumber();

	std::vector<int> organizedVec = this->_vec;
	std::sort(organizedVec.begin(), organizedVec.end());

	int tempSpan = std::numeric_limits<int>::max();
	int span;

	for (size_t i = 1; i < organizedVec.size(); i++)
	{
		span = organizedVec[i] - organizedVec[i - 1];
		if (tempSpan > span)
			tempSpan = span;
	}
	return (tempSpan);
}

int Span::longestSpan()
{
	if (this->_N < 2)
		throw ToLowNumber();
	std::vector<int>::iterator iterator;

	int maxNumber = *std::max_element(this->_vec.begin(), this->_vec.end());
	int minNumber = *std::min_element(this->_vec.begin(), this->_vec.end());
	
	return (maxNumber - minNumber);
}


void Span::addNumber(int number)
{
	if (this->_vec.size() < _N)
	{
		_vec.push_back(number);
	}
	else
	{
		throw NoSpaceLeft();
	}
}

void Span::printVec(void)
{
	std::cout << magenta << "\nSize: " << green << this->_N << "\n" << reset;
	for(size_t i = 0; i < this->_vec.size(); i++)
	{
		std::cout << magenta << "Current Vec: " \
			<< green << this->_vec[i] << "\n" << reset;
	}
}


Span::Span(unsigned int number)
	: _N(number)
{
	//std::cout << magenta << "Span Number Constructor Called\n" << reset;

}

Span::Span()
	: _N(0)
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
	this->_vec = copy._vec;
}

Span &Span::operator=(const Span &copy)
{
	//std::cout << cyan << "Span Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_N = copy._N;
		this->_vec = copy._vec;
	}
	return (*this);
}

const char* NoSpaceLeft::what() const throw()
{
	return "Error: No space left in the Container!";
}

const char* ToLowNumber::what() const throw()
{
	return "Error: You got to have at least 2 numbers in the container!";
}