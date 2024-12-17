/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:23:42 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/17 17:52:07 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkInput(std::string date, float value)
{
	(void)value;
	size_t pos1 = date.find("-");
	size_t pos2 = date.find("-" , pos1 + 1);

	std::string year = date.substr(0, pos1);
	std::string month = date.substr(pos1 + 1, pos2 - pos1 - 1);
	std::string days = date.substr(pos2 + 1);

	//Check if is empty
	if (year.empty() || month.empty() || days.empty())
	{
		std::cout << "ERRO! empty" << "\n";
		return (false);
	}
	//check if a valid month
	else if(std::atoi(month.c_str()) > 12 || std::atoi(month.c_str()) < 1)
	{
		std::cout << "ERRO! invalid month" << "\n";
		return (false);
	}

	// std::cout << "year: >" << year << "<\n";
	// std::cout << "month: >" << month << "<\n";
	// std::cout << "days: >" << days << "<\n";

	// std::cout << "Value: " << value << "\n";
	// std::cout << "\n";
	// std::cout << "\n";
	return (true);
}


void BitcoinExchange::readInput(std::string input)
{
	std::string arrayString;
	std::string date;
	std::string value;

	std::ifstream theFile(input.c_str());
	if (theFile.fail())
	{
		std::cout << "FALHOU" << "\n";
		return ;
	}
	int tempI = 0;
	while(getline(theFile, arrayString))
	{
		if (tempI > 0)
		{
			date = arrayString.substr(0, arrayString.find("|") - 1);
			value = arrayString.substr(arrayString.find("|") + 2);

			if (checkInput(date, std::atof(value.c_str())))
			{
				std::cout << "Passed" << "\n";
				// std::cout << "data: " << date << "\n";
				// std::cout << "value: " << value << "\n";
				// std::cout << "\n";

			}
			else
			{
				std::cout << "RIP!" << "\n";
			}
		}
		tempI++;
	}
}

void BitcoinExchange::readTheFileToDataBase()
{
	std::string arrayString;
	std::string data;
	std::string value;

	std::ifstream theFile("data.csv");
	int tempI = 0;
	while(getline(theFile, arrayString))
	{
		if (tempI > 0)
		{
			data = arrayString.substr(0, arrayString.find(","));
			value = arrayString.substr(arrayString.find(",") + 1);
			this->database.insert(std::pair<std::string, float>(data, std::atof(value.c_str())));
		}
		tempI++;
	}


	
}





BitcoinExchange::BitcoinExchange()
{
	//std::cout << magenta << "BitcoinExchange Default Constructor Called\n" << reset;
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << red << "BitcoinExchange Destructor Called\n" << reset;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	//std::cout << cyan << "BitcoinExchange Copy Constructor Called\n" << reset;
	this->database = copy.database;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	//std::cout << cyan << "BitcoinExchange Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->database = copy.database;
	}
	return (*this);
}