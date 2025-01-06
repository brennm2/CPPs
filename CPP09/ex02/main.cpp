/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:47 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/06 16:33:18 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void checkIfNumber(int ac, char **av)
{
	std::string tempStr;

	for (int j = 1; j < ac; j++)
	{
		size_t i = 0;
		tempStr = av[j];
		while(i < tempStr.size())
		{
			if (!isdigit(tempStr[i]))
			{
				throw std::runtime_error("Syntax Error! Not a number!");
				return ;
			}
			i++;
		}
	}
}

void checkIfNegative(int ac, char **av)
{
	int i = 1;
	std::string tempStr;

	while(i < ac)
	{
		tempStr = av[i];
		if ( std::strtol(tempStr.c_str(), NULL, 0) < 0)
		{
			throw std::runtime_error("Syntax Error! Negative number!");
			return ;
		}
		i++;
	}
}

void	syntaxChecker(int ac, char **av)
{
	if (ac < 2)
		throw std::runtime_error("Wrong number of arguments!\nTry something like: ./PmergeMe 3 5 9 7 4");
	checkIfNegative(ac, av);
	checkIfNumber(ac, av);

}

int main(int ac, char **av)
{
	try
	{
		syntaxChecker(ac, av);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	
}