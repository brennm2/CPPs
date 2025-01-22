/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:47 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/22 17:00:54 by bde-souz         ###   ########.fr       */
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

void printAfter(PmergeMe &numbers, int option)
{
	switch (option)
	{
		case 1 :
			std::cout << green << "After: " << reset ;
			numbers.printVector(numbers.getOrganizedVector());
			break;
		case 2 :
			std::cout << green << "After: " << reset ;
			numbers.printDeque(numbers.getOrganizedDeque());
			break;
	}
}

void printTimer(std::clock_t start, std::clock_t end, int ac, int option)
{
	double finalTime = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	switch (option)
	{
	case 1:
		std::cout << "Time to process a range of " << green << ac - 1 << reset
			<< " elements with std::vector: " << green << std::fixed << std::setprecision(5) << finalTime << reset << " us" << "\n";
		break;
	case 2:
		std::cout << "Time to process a range of " << green << ac - 1 << reset
			<< " elements with std::deque: " << green << std::fixed << std::setprecision(5) << finalTime << reset << " us" << "\n";
		break;
	}
}


int main(int ac, char **av)
{
	PmergeMe Numbers;
	try
	{
		syntaxChecker(ac, av);
		Numbers.argsToVector(ac, av);
		Numbers.argsToDeque(ac, av);
		printBefore(ac, av);

		std::clock_t startClock;
		std::clock_t endClock;

		// Vector
		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "VECTOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		startClock = std::clock();
		Numbers.organizeVector();
		endClock = std::clock();
		printAfter(Numbers, 1);
		printTimer(startClock, endClock, ac, 1);


		// Deque
		startClock = std::clock();
		Numbers.organizeDeque();
		endClock = std::clock();
		printTimer(startClock, endClock, ac, 2);


		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "DEQUE" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		printAfter(Numbers, 2);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	
}