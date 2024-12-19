/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:05:55 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/19 11:16:28 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::isValidOperator(std::string input)
{
	if (input.size() == 1 && (input == "-" || input == "+" \
		|| input == "*" || input == "/"))
	{
		if (this->_numberStack.size() < 2)
		{
			throw std::runtime_error("Operator Syntax Error!");
			return (false);
		}
	}
	else
		throw std::runtime_error("Operator Syntax Error!");
	return (true);
}

bool RPN::isValidNumber(std::string input)
{
	if (input.size() > 1 || this->_numberStack.size() > 2)
		throw std::runtime_error("Number Syntax Error!");

	if (!std::isdigit(input[0]))
	{
		return (false);
	}
	return (true);
}

void RPN::calculation(std::string input)
{
	std::istringstream splited(input);
	std::string str;
	long number;
	
	while (splited >> str)
	{
		if (this->isValidNumber(str))
		{
			number = std::atol(str.c_str());
			this->_numberStack.push(number);
		}
		else if (this->isValidOperator(str))
		{
			long numberB = this->_numberStack.top();
			this->_numberStack.pop();
			long numberA = this->_numberStack.top();
			this->_numberStack.pop();
			
			long result = 0;
			if (str == "+")
			{
				result = numberA + numberB;
				if (result > MAX_INT || result < MIN_INT)
					throw std::runtime_error("Number Overflow!");
			}
			else if (str == "*")
			{
				if (numberA > MAX_INT || numberB >> MAX_INT)
					throw std::runtime_error("Number Overflow!");
				result = numberA * numberB;
			}
			this->_numberStack.push(result);
		}
		else
			throw std::runtime_error("Syntax Error what!");
	}
	std::cout << "Result: " << this->_numberStack.top() << "\n";
}



RPN::RPN()
{
	//std::cout << magenta << "RPN Default Constructor Called\n" << reset;
}

RPN::~RPN()
{
	//std::cout << red << "RPN Destructor Called\n" << reset;
}

RPN::RPN(const RPN &copy)
{
	// std::cout << cyan << "RPN Copy Constructor Called\n" << reset;
	this->_numberStack = copy._numberStack;
}

RPN &RPN::operator=(const RPN &copy)
{
	// std::cout << cyan << "RPN Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_numberStack = copy._numberStack;
	}
	return (*this);
}