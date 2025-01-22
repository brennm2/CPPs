/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:23:42 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/22 15:20:18 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool checkIfNumber(std::string str)
{
	int dotNumber = 0;
	std::string::const_iterator it = str.begin();
	while (it != str.end())
	{
		if ((std::isdigit(*it) || *it == '.') && dotNumber < 2)
		{
			if (*it == '.')
				dotNumber++;
			it++;
		}
		else
			return (false);
	}
	if (str.empty())
		return (false);
	return (true);
}

bool checkInput(std::string date, std::string value)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << red << "Error: Bad input => " << date << "\n" << reset;
		return (false);
	}
	if (std::atof(value.c_str()) < 0)
	{
		std::cerr << red << "Error: not a positive number." << reset << "\n";
		return (false);
	}
	if (std::atof(value.c_str()) > 1000)
	{
		std::cerr << red << "Error: too large a number." << reset << "\n";
		return (false);
	}
	if (!checkIfNumber(value))
	{
		std::cerr << red << "Error: Bad input (invalid value) => " << date << "\n" << reset;
		return (false);
	}

	size_t pos1 = date.find("-");
	size_t pos2 = date.find("-", pos1 + 1);

	std::string stringYear = date.substr(0, pos1);
	std::string stringMonth = date.substr(pos1 + 1, pos2 - pos1 - 1);
	std::string stringDays = date.substr(pos2 + 1);
	int year = std::atoi(stringYear.c_str());
	int month = std::atoi(stringMonth.c_str());
	int days = std::atoi(stringDays.c_str());


	//Check if is empty
	if (stringYear.empty() || stringDays.empty() || stringDays.empty())
	{
		std::cerr << red << "Error: Bad input (empty date) =>" << date << "\n" << reset;
		return (false);
	}
	//check if is all numbers
	else if (!checkIfNumber(stringYear) || !checkIfNumber(stringMonth) || !checkIfNumber(stringYear))
	{
		std::cerr << red << "Error: Bad input (not all numbers) => " << date << "\n" << reset;
		return (false);
	}

	//check if a valid month
	else if(month > 12 || month < 1)
	{
		std::cerr << red << "Error: Bad input (invalid month)=> " << date << "\n" << reset;
		return (false);
	}
	//check if is a valid year
	else if (year < 1900 || year > 2100)
	{
		std::cerr << red << "Error: Bad input (invalid year)=> " << date << "\n" << reset;
		return (false);
	}
	//check for days
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if ((year % 4 == 0 && year % 100 != 0) \
		|| year % 400 == 0)
		daysInMonth[1] = 29;
	if (days < 1 || days > daysInMonth[month - 1])
	{
		std::cerr << red << "Error: Bad input (invalid day) => " << date << "\n" << reset;
		return (false);
	}
	return (true);
}

void getValueDataBase(std::map<std::string, float> dataBase, std::string date, float value)
{

	std::map<std::string, float>::iterator it;
	it = dataBase.lower_bound(date);
	if (it != dataBase.begin() && (it == dataBase.end() || it->first != date))
		--it;
	std::cout << date << " => ";
	std::cout << value << " = ";

	float result = it->second * value;

	if (result > 1000000.0)
		std::cout << std::fixed << std::setprecision(2) << result << "\n";
	else
		std::cout << result << "\n";


}


void BitcoinExchange::readInput(std::string input)
{
	std::string arrayString;
	std::string date;
	std::string value;

	std::ifstream theFile(input.c_str());
	if (theFile.fail())
	{
		throw std::runtime_error("Failed to open the file");
		return ;
	}
	int tempI = 0;
	while(getline(theFile, arrayString))
	{
		if (tempI > 0)
		{
			if (arrayString.empty())
				std::cerr << "Error: Bad input (empty line)"<< "\n";
			else
			{
				date = arrayString.substr(0, arrayString.find("|") - 1);
				value = arrayString.substr(arrayString.find("|") + 2);
				if (checkInput(date, value))
				{
					getValueDataBase(this->database, date, std::atof(value.c_str()));
				}
			}
		}
		tempI++;
	}
}

bool BitcoinExchange::readTheFileToDataBase()
{
	std::string arrayString;
	std::string data;
	std::string value;

	std::ifstream theFile("data.csv");
	if (theFile.fail())
	{
		throw std::runtime_error("Problem with DataBase file");
		return (false);
	}
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
	return (true);
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


