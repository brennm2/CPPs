/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:52 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/07 18:49:14 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::printVector(void)
{
	for (size_t i = 0; i < this->_vector.size(); i++)
	{
		std::cout << this->_vector[i] << " ";
	}
	std::cout << "\n";
	
}

void PmergeMe::argsToVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		this->_vector.push_back(std::strtol(av[i], NULL, 0));
	}
	printVector();
}



PmergeMe::PmergeMe()
{
	//std::cout << magenta << "PmergeMe Default Constructor Called\n" << reset;
}

PmergeMe::~PmergeMe()
{
	//std::cout << red << "PmergeMe Destructor Called\n" << reset;
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	//std::cout << cyan << "PmergeMe Copy Constructor Called\n" << reset;
	*this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	//std::cout << cyan << "PmergeMe Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}