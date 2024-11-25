/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:54:03 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/25 17:26:37 by bde-souz         ###   ########.fr       */
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
	char tempChar = c[0];
	
	std::cout << "char: '" << tempChar << "'\n";

	//string to int
	int tempInt = static_cast<int>(c[0]);
	std::cout << "int: " << tempInt << "\n";

	//string to float
	float tempFloat = tempInt;
	std::cout << std::fixed << std::setprecision(2) << "float: " << tempFloat << "f" << "\n";
	
	//string to double
	double tempDouble = tempInt;
	std::cout << std::fixed << std::setprecision(2) << "double: " << tempDouble << "\n";

}

void	ScalarConverter::intConverter(std::string c)
{
	std::stringstream ss(c);
	long int tempStringToInt;
	ss >> tempStringToInt;
	
	//string(int) to char
	if (tempStringToInt < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (tempStringToInt > 127)
		std::cout << "char: impossible" << "\n";
	else
		std::cout << "char: '" << static_cast<char>(tempStringToInt) << "'\n";


	//string to int
	if (tempStringToInt > 2147483647 || tempStringToInt < -2147483648)
		std::cout << "int: " << "impossible" << "\n";
	else
		std::cout << "int: " << tempStringToInt << "\n";
	

	//string to float
	float tempFloat = atof(c.c_str());
	std::cout << std::fixed << std::setprecision(2) << "float: " << tempFloat << "f" << "\n";

	//string to double
	double tempDouble = atof(c.c_str());
	std::cout << std::fixed << std::setprecision(2) << "double: " << tempDouble  << "\n";
	
}

void	ScalarConverter::floatConverter(std::string c)
{
	std::stringstream ss(c);
	long int tempStringToInt;
	ss >> tempStringToInt;

	//string(float) to char --------
	if (tempStringToInt < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (tempStringToInt > 127)
		std::cout << "char: impossible" << "\n";
	else
		std::cout << "char: '" << static_cast<char>(tempStringToInt) << "'\n";


	//string(float) to int --------
	if (tempStringToInt > 2147483647 || tempStringToInt < -2147483648)
		std::cout << std::setprecision(2) << "int: " << "impossible" << "\n";
	else
		std::cout << std::setprecision(2) << "int: " << tempStringToInt << "\n";


	//string(float) to float --------
	float tempFloat = atof(c.c_str());
	std::cout << "float: " << std::fixed << std::setprecision(2) << tempFloat << "f" << "\n";


	//string(float) to double --------
	double tempDouble = atof(c.c_str());
	std::cout << "double: " << std::fixed << std::setprecision(2) << tempDouble << "\n";
}

void	ScalarConverter::doubleConverter(std::string c)
{
	std::stringstream ss(c);
	long int tempStringToInt;
	ss >> tempStringToInt;

	//string(double) to char --------
	if (tempStringToInt < 32)
		std::cout << "char: Non displayable" << "\n";
	else if (tempStringToInt > 127)
		std::cout << "char: impossible" << "\n";
	else
		std::cout << "char: '" << static_cast<char>(tempStringToInt) << "'\n";

	//string(double) to int --------
	if (tempStringToInt > 2147483647 || tempStringToInt < -2147483648)
		std::cout << std::setprecision(2) << "int: " << "impossible" << "\n";
	else
		std::cout << std::setprecision(2) << "int: " << tempStringToInt << "\n";

	//string(double) to float --------
	float tempFloat = atof(c.c_str());
	std::cout << "float: " << std::fixed << std::setprecision(2) << tempFloat << "f" << "\n";

	//string(double) to double --------
	double tempDouble = atof(c.c_str());
	std::cout << "double: " << std::fixed << std::setprecision(2) << tempDouble << "\n";
}

void	ScalarConverter::nanOrInfConverter(std::string c)
{
	if (c == "nan")
	{
		//string(nanOrInf) to char --------
		std::cout << "char: impossible" << "\n";


		//string(nanOrInf) to int --------
		std::cout << "int: impossible" << "\n";


		//string(nanOrInf) to float --------
		float tempFloat = atof(c.c_str());
		std::cout << "float: " << std::fixed << std::setprecision(2) << tempFloat << "f" << "\n";


		//string(nanOrInf) to double --------
		double tempDouble = atof(c.c_str());
		std::cout << "double: " << std::fixed << std::setprecision(2) << tempDouble << "\n";
	}
	else
	{
		//string(nanOrInf) to char --------
		std::cout << "char: impossible" << "\n";


		//string(nanOrInf) to int --------
		std::cout << "int: impossible" << "\n";


		//string(nanOrInf) to float --------
		float tempFloat = atof(c.c_str());
		std::cout << "float: " << std::fixed << std::setprecision(2) << tempFloat << "f" << "\n";


		//string(nanOrInf) to double --------
		double tempDouble = atof(c.c_str());
		std::cout << "double: " << std::fixed << std::setprecision(2) << tempDouble << "\n";
	}
}

void	ScalarConverter::converter(std::string c)
{
	ScalarConverter sc;
	int type = sc.checkTheType(c);

	// 0 = char / 1 = int / 2 = float / 3 = double
	std::cout << "Type: " << type << "\n\n";
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