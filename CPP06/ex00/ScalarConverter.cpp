/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:54:03 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/27 13:27:41 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool isAllDigit(std::string string)
{
	size_t i = 0;

	if ((string[0] == '+' || string[0] == '-'))
		i++;
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
	if ((string[0] == '+' || string[0] == '-') && std::isdigit(string[1]))
		return (true);
	else
		return (false);
}

bool	checkIsDouble(std::string string)
{
	size_t i = 0;
	bool hasDotFlag = false;

	if ((string[0] == '+' || string[0] == '-'))
		i++;
	while (i < string.size())
	{
		if (!std::isdigit(string[i]) && string[i] != '.')
			break ;
		if (string[i] == '.')
			hasDotFlag = !hasDotFlag;
		i++;
	}
	if (i == string.size() && hasDotFlag == true)
		return (true);
	else
		return (false);
}

bool	checkIsFloat(std::string string)
{
	size_t i = 0;
	bool hasDotFlag = false;

	if ((string[0] == '+' || string[0] == '-'))
		i++;
	while (i < string.size())
	{
		if (!std::isdigit(string[i]) && string[i] != '.')
			break ;
		if (string[i] == '.')
			hasDotFlag = !hasDotFlag;
		i++;
	}
	if (string[i] == 'f' && i == string.size() - 1 \
		&& hasDotFlag == true && string[i - 1] != '.')
		return (true);
	else
		return (false);
}

bool	checkIsNanOrInf(std::string string)
{
	if (string == "+inf" || string == "-inf" || string == "nan")
		return (true);
	else
		return (false);
}


int	ScalarConverter::checkTheType(std::string type)
{

	// 0 = char / 1 = int / 3 = float / 4 = double
	if (type.size() == 1 && (!std::isdigit(type[0])))
		return (0);
	else if (isAllDigit(type))
		return (1);
	else if (checkIsFloat(type))
		return (2);
	else if (checkIsDouble(type))
		return (3);
	else if (checkIsNanOrInf(type))
		return (4);
	return (5);
}


void ScalarConverter::charConverter(std::string c)
{
	ScalarConverter sc;

	//string to char
	char tempChar = static_cast<char>(c[0]);
	
	std::cout << "char: '" << tempChar << "'\n";

	//string to int
	int tempInt = static_cast<int>(c[0]);
	std::cout << "int: " << tempInt << "\n";

	//string to float
	float tempFloat = static_cast<float>(tempInt);
	std::cout << std::fixed << std::setprecision(2) << "float: " << tempFloat << "f" << "\n";
	
	//string to double
	double tempDouble = static_cast<double>(tempInt);
	std::cout << std::fixed << std::setprecision(2) << "double: " << tempDouble << "\n";

}

void	ScalarConverter::intConverter(std::string c)
{
	double tempStringToIntDouble = std::strtod(c.c_str(), NULL);
	float tempStringToIntFloat = std::atof(c.c_str());
	int tempStringToInt = std::atoi(c.c_str());


	//string(int) to char
	if (tempStringToIntDouble < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (tempStringToIntDouble > 127)
		std::cout << "char: impossible" << "\n";
	else
		std::cout << "char: '" << static_cast<char>(tempStringToInt) << "'\n";


	//string(int) to int
	if (tempStringToIntDouble > 2147483647 || tempStringToIntDouble < -2147483648)
		std::cout << "int: " << "impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(tempStringToInt) << "\n";


	//string(int) to float
	std::cout << std::fixed << std::setprecision(2) << "float: " \
		<< static_cast<float>(tempStringToIntFloat) << "f" << "\n";

	//string(int) to double
	std::cout << std::fixed << std::setprecision(2) << "double: " \
		<< static_cast<double>(tempStringToIntDouble) << "\n";
	
}

void	ScalarConverter::floatConverter(std::string c)
{
	double tempStringToIntDouble = std::strtod(c.c_str(), NULL);
	float tempStringToIntFloat = std::atof(c.c_str());
	int tempStringToInt = std::atoi(c.c_str());


	//string(float) to char --------
	if (tempStringToIntDouble < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (tempStringToIntDouble > 127)
		std::cout << "char: impossible" << "\n";
	else
		std::cout << "char: '" << static_cast<char>(tempStringToInt) << "'\n";


	//string(float) to int --------
	if (tempStringToIntDouble > 2147483647 || tempStringToIntDouble < -2147483648)
		std::cout << "int: " << "impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(tempStringToInt) << "\n";


	//string(float) to float --------
	std::cout << std::fixed << std::setprecision(2) << "float: " \
		<< static_cast<float>(tempStringToIntFloat) << "f" << "\n";

	//string to double
	std::cout << std::fixed << std::setprecision(2) << "double: " \
		<< static_cast<double>(tempStringToIntDouble) << "\n";
}

void	ScalarConverter::doubleConverter(std::string c)
{
	double tempStringToIntDouble = std::strtod(c.c_str(), NULL);
	float tempStringToIntFloat = std::atof(c.c_str());
	int tempStringToInt = std::atoi(c.c_str());


	//string(double) to char --------
	if (tempStringToInt < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (tempStringToInt > 127)
		std::cout << "char: impossible" << "\n";
	else
		std::cout << "char: '" << static_cast<char>(tempStringToInt) << "'\n";

	//string(double) to int --------
	if (tempStringToIntDouble > 2147483647 || tempStringToIntDouble < -2147483648)
		std::cout << "int: " << "impossible" << "\n";
	else
		std::cout << "int: " << static_cast<int>(tempStringToInt) << "\n";

	//string(double) to float --------
	std::cout << std::fixed << std::setprecision(2) << "float: " \
		<< static_cast<float>(tempStringToIntFloat) << "f" << "\n";


	//string(double) to double --------
	std::cout << std::fixed << std::setprecision(2) << "double: " \
		<< static_cast<double>(tempStringToIntDouble) << "\n";
}

void	ScalarConverter::nanOrInfConverter(std::string c)
{
	double tempStringToIntDouble = std::strtod(c.c_str(), NULL);
	float tempStringToIntFloat = std::atof(c.c_str());

	//string(nanOrInf) to char --------
	std::cout << "char: impossible" << "\n";


	//string(nanOrInf) to int --------
	std::cout << "int: impossible" << "\n";


	//string(nanOrInf) to float --------
	std::cout << std::fixed << std::setprecision(2) << "float: " \
		<< static_cast<float>(tempStringToIntFloat) << "f" << "\n";


	//string(nanOrInf) to double --------
	std::cout << std::fixed << std::setprecision(2) << "double: " \
		<< static_cast<double>(tempStringToIntDouble) << "\n";
}

void	ScalarConverter::converter(std::string c)
{
	ScalarConverter sc;
	int type = sc.checkTheType(c);

	// 0 = char / 1 = int / 2 = float / 3 = double
	switch (type)
	{
		case 0:
			sc.charConverter(c);
			break;
		case 1:
			sc.intConverter(c);
			break;
		case 2:
			sc.floatConverter(c);
			break;
		case 3:
			sc.doubleConverter(c);
			break;
		case 4:
			sc.nanOrInfConverter(c);
			break ;
		case 5:
			std::cout << red << "Bad Input!" << "\n" << reset;
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
	// std::cout << cyan << "ScalarConverter Copy Constructor Called\n" << reset;
	(void)copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	// std::cout << cyan << "ScalarConverter Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}