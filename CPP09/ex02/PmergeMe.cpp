/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:52 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/08 18:47:06 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void PmergeMe::printVector(std::vector<long> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
	
}

void PmergeMe::printPairs(std::vector<std::pair<long, long> > &pair)
{
	for (size_t i = 0; i < pair.size(); i++)
	{
		std::cout << "(" << pair[i].first << ", " << pair[i].second << ") ";
	}
	if (this->_vector.size() % 2 != 0)
	{
		std::cout << "(" << this->_vectorLastElement << ", NONE)"; // Imprime o último elemento se o número de elementos for ímpar.
	}
	std::cout << "\n";
}

// void PmergeMe::printPairs(std::vector<std::pair<long, long> > &pairs)
// {
// 	for (std::vector<std::pair<long, long> >::iterator it = pairs.begin(); it != pairs.end(); it++)
// 		std::cout << it->first << " " << it->second << std::endl;
// 	std::cout << std::endl;
// }

// void PmergeMe::printVector(std::vector<long> &vector)
// {
// 	for (std::vector<long>::iterator it = vector.begin(); it != vector.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

void PmergeMe::argsToVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		this->_vector.push_back(std::strtol(av[i], NULL, 0));
	}
	// printVector(); // DEBUG
}

void PmergeMe::splitIntoPairsVector(void)
{
	for (size_t i = 0; i < this->_vector.size(); i += 2)
	{
		if (i + 1 < this->_vector.size())
			this->_vectorPairs.push_back(std::make_pair(this->_vector[i], this->_vector[i + 1]));
		else
			this->_vectorLastElement = this->_vector[i];
	}
}

void PmergeMe::organizePairsVector(void)
{
	for (size_t i = 0; i < _vectorPairs.size(); i++)
	{
		if (_vectorPairs[i].second < _vectorPairs[i].first)
			std::swap(_vectorPairs[i].first, _vectorPairs[i].second);
	}
}

void PmergeMe::organizePairVectorRecursively(std::vector<std::pair<long, long> > &pairs)
{
	if(pairs.size() <= 1)
		return ;
	
	int middle = pairs.size() / 2;

	std::vector<std::pair<long, long> > upPair(pairs.begin(), pairs.begin() + middle);
	std::vector<std::pair<long, long> > downPair(pairs.begin() + middle, pairs.end());

	organizePairVectorRecursively(upPair);
	organizePairVectorRecursively(downPair);

	std::vector<std::pair<long, long> > sortedPairs;

	size_t upI = 0;
	size_t downI = 0;

	while (upI < upPair.size() && downI < downPair.size())
	{
		if (upPair[upI].second <= downPair[downI].second)
		{
			sortedPairs.push_back(upPair[upI]);
			++upI;
		}
		else
		{
			sortedPairs.push_back(downPair[downI]);
			++downI;
		}
	}
	
	// Restante
	while(upI < upPair.size())
	{
		sortedPairs.push_back(upPair[upI]);
		++upI;
	}
	while(downI < downPair.size())
	{
		sortedPairs.push_back(downPair[downI]);
		++downI;
	}
	pairs.clear();
	pairs = sortedPairs;
}

void PmergeMe::putSmallestNumberinVector(void)
{
	if (this->_vector.size() % 2 == 0 && this->_vectorPairs.size() == 1)
	{
		std::cout << red << "SmallestNumber condition" << "\n" << reset;
		return ;
	}
	else
	{
		this->_vectorOrganized.insert(this->_vectorOrganized.begin(), this->_vectorPairs[0].first);
	}
	
}

void PmergeMe::organizeVector(void)
{
	// Phase 1
	splitIntoPairsVector();

	// Phase 2
	organizePairsVector();
	printPairs(this->_vectorPairs); //DEBUG

	// Phase 3
	organizePairVectorRecursively(this->_vectorPairs);
	std::cout << "\nFASE 3" << "\n";
	printPairs(this->_vectorPairs); //DEBUG

	// Put the biggest numbers in the _vectorOrganized
	// If a odd number, just push the _vectorLastElement;
	if (this->_vector.size() % 2 == 0)
	{
		for (std::vector<std::pair<long, long> >::iterator it = _vectorPairs.begin(); it != _vectorPairs.end(); it++)
			_vectorOrganized.push_back(it->second);
	}
	else
		this->_vectorOrganized.push_back(_vectorLastElement);

	
	std::cout << "\nVector atual: ";
	printVector(this->_vectorOrganized); //DEBUG

	// Phase 4
	
	putSmallestNumberinVector();
	std::cout << "\nVector atual, fase 4: ";
	printVector(this->_vectorOrganized); //DEBUG



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