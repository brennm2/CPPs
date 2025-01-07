/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:47 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/07 18:53:47 by bde-souz         ###   ########.fr       */
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

void printBefore(int ac, char **av)
{
	std::cout << blue << "Before: " << reset;
	for (int i = 1; i < ac; i++)
	{
		std::cout << av[i] << " ";
	}
	std::cout << "\n";
	
}

void printTimer(std::clock_t start, std::clock_t end, int ac)
{
	std::clock_t
	std::cout << "Time to process a range of " << "\n";
}

int main(int ac, char **av)
{
	PmergeMe Numbers;
	try
	{
		syntaxChecker(ac, av);
		printBefore(ac, av);
		Numbers.argsToVector(ac, av);

		std::clock_t startClock;
		std::clock_t endClock;

		startClock = std::clock();
		endClock = std::clock();


		
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	
}