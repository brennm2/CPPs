/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:54:03 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/21 18:54:23 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isAllDigit(std::string string)
{
	size_t i = 0;

	while(i < string.size())
	{
		if (!std::isdigit(string[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	hasSignal(std::string string)
{
	if (string[0] == '+' || string[0] == '-')
		return (true);
	else
		return (false);
}

int	ScalarConverter::checkTheType(std::string type)
{

	// 0 = char / 1 = int / 3 = float / 4 = double
	if (type.size() == 1 && (!std::isdigit(type[0])))
		return (0);
	else if (isAllDigit(type) || hasSignal(type))
		return (1);
	// else if (...)
	// 	return (2);
	// else if
	// 	return (3);
	return (5);
}

void ScalarConverter::charConverter(std::string c)
{
	ScalarConverter sc;

	//string to char
	char tempChar = c[0];
	std::cout << "char: " << tempChar << "\n";

	//string to int
	int tempInt = static_cast<int>(c[0]);
	std::cout << "int: " << tempInt << "\n";

	//string to float
	std::cout << "float: " << tempInt << ".0f" << "\n";
	
	//string to double
	std::cout << "double: " << tempInt << ".0" << "\n";

}

void	ScalarConverter::intConverter(std::string c)
{
	//string(int) to char
	std::cout << "char: " << c << "\n";

	//string to int
	std::stringstream ss(c);
	long int tempInt;
	ss >> tempInt;
	if (tempInt > 2147483647 || tempInt < -2147483648)
		std::cout << "int: " << "impossible" << "\n";
	else
		std::cout << "int: " << tempInt << "\n";
	

	//string to float
	float tempFloat = atof(c.c_str());
	std::cout << "float: " << tempFloat << ".0f" << "\n";

	//string to double
	float tempDouble = atof(c.c_str());
	std::cout << "float: " << tempDouble << ".0" << "\n";
	
}

void	ScalarConverter::converter(std::string c)
{
	ScalarConverter sc;
	int type = sc.checkTheType(c);

	// 0 = char / 1 = int / 3 = float / 4 = double
	std::cout << "Type: " << type << "\n\n";
	switch (type)
	{
		case 0:
			sc.charConverter(c);
			break;
		case 1:
			sc.intConverter(c);
			break;
		case 5:
			std::cout << "WRONG!" << "\n";
			break;
	}
}


ScalarConverter::ScalarConverter()
{
	//std::cout << magenta << "ScalarConverter Default Constructor Called\n" << reset;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << red << "ScalarConverter Destructor Called\n" << reset;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << cyan << "ScalarConverter Copy Constructor Called\n" << reset;
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	std::cout << cyan << "ScalarConverter Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}