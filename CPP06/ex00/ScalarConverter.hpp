/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:54:00 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/26 16:57:28 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>


// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


class ScalarConverter
{
private:
	static int		checkTheType(std::string type);
	static void	intConverter(std::string c);
	static void	charConverter(std::string c);
	static void	floatConverter(std::string c);
	static void	doubleConverter(std::string c);
	static void	nanOrInfConverter(std::string c);

	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);
	ScalarConverter &operator=(const ScalarConverter &copy);
	
public:
	void static	converter(std::string c);
} ;

#endif