/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:52 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/20 14:00:50 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//------------------------------------//
//              DEQUE                 //
// -----------------------------------//

void PmergeMe::organizeDeque(void)
{
	// Phase 1
	splitIntoPairsDeque();
	if (this->_deque.size() == 1)
	{
		this->_dequeOrganized.push_back(this->_deque[0]);
		return ;
	}

	// Phase 2
	organizePairsDeque();
	//printPairsDeque(this->_dequePairs); //DEBUG

	// Phase 3
	organizePairDequeRecursively(this->_dequePairs);
	//std::cout << "\nFASE 3" << "\n";
	//printPairsDeque(this->_dequePairs); //DEBUG
	
	// Put the biggest numbers in the _vectorOrganized
	for (std::deque<std::pair<long, long> >::iterator it = _dequePairs.begin(); it != _dequePairs.end(); it++)
		_dequeOrganized.push_back(it->second);

	//std::cout << "\nVector atual, fase 3: ";
	//printDeque(this->_dequeOrganized); //DEBUG

	// Phase 4
	putSmallestNumberInDeque();
	//std::cout << "\nVector atual, fase 4: ";
	//printDeque(this->_dequeOrganized); //DEBUG

	// Phase 5
	putTheRestDeque();
	//std::cout << "\nVector atual, fase 5: ";
	//printDeque(this->_dequeOrganized); //DEBUG
}


void PmergeMe::splitIntoPairsDeque(void)
{
	for (size_t i = 0; i < this->_deque.size(); i += 2)
	{
		if (i + 1 < this->_deque.size())
			this->_dequePairs.push_back(std::make_pair(this->_deque[i], this->_deque[i + 1]));
		else
		{
			this->_oddDeque = true;
			this->_dequeLastElement = this->_deque[i];
		}
	}
}

void PmergeMe::organizePairsDeque(void)
{
	for (size_t i = 0; i < _dequePairs.size(); i++)
	{
		if (_dequePairs[i].second < _dequePairs[i].first)
			std::swap(_dequePairs[i].first, _dequePairs[i].second);
	}
}

void PmergeMe::organizePairDequeRecursively(std::deque<std::pair<long, long> > &pairs)
{
	if(pairs.size() <= 1)
		return ;
	
	int middle = pairs.size() / 2;

	std::deque<std::pair<long, long> > upPair(pairs.begin(), pairs.begin() + middle);
	std::deque<std::pair<long, long> > downPair(pairs.begin() + middle, pairs.end());

	organizePairDequeRecursively(upPair);
	organizePairDequeRecursively(downPair);

	std::deque<std::pair<long, long> > sortedPairs;

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

void PmergeMe::putSmallestNumberInDeque(void)
{
	this->_dequeOrganized.insert(this->_dequeOrganized.begin(), this->_dequePairs[0].first);
}

void PmergeMe::putTheRestDeque(void)
{
	std::deque<long> jacob;
	
	jacob = createJacobDeque();

	//std::cout << "\nJACOB: ";
	//printDeque(jacob); // DEBUG

	for (size_t i = 1; i < jacob.size(); i++)
	{
		for (size_t j = jacob[i]; (long)j > jacob[i - 1]; j--)
		{
			if (j >= this->_dequePairs.size())
			{
				if (this->_dequePairs.size() == 1 && this->_oddDeque == true)
					binarySearchDeque(this->_dequeLastElement);
				continue;
			}
			binarySearchDeque(this->_dequePairs[j].first);
			if(this->_dequeOrganized.size() == (2 *(_dequePairs.size())))
			{
				if (this->_oddDeque == true)
					binarySearchDeque(this->_dequeLastElement);
				return ;
			}
		}
	}
}

// ----------------- DEQUE HELPERS ------------------- //

void PmergeMe::printDeque(std::deque<long> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << "\n";
}


void PmergeMe::printPairsDeque(std::deque<std::pair<long, long> > &pair)
{
	for (size_t i = 0; i < pair.size(); i++)
		std::cout << "(" << pair[i].first << ", " << pair[i].second << ") ";
	if (this->_deque.size() % 2 != 0)
		std::cout << "(" << this->_dequeLastElement << ", NONE)";
	std::cout << "\n";
}

void PmergeMe::argsToDeque(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		this->_deque.push_back(std::strtol(av[i], NULL, 0));
}

std::deque<long> PmergeMe::createJacobDeque(void)
{
	std::deque<long> tempJacob;

	if (this->_dequePairs.size() == 0)
		tempJacob.push_back(0);
	else if (this->_dequePairs.size() == 1)
	{
		tempJacob.push_back(0);
		tempJacob.push_back(1);
	}
	else
	{
		tempJacob.push_back(0);
		tempJacob.push_back(1);

		for (size_t i = 2; \
			static_cast<size_t>(tempJacob[i - 1] + 2 * tempJacob[i - 2]) < (2 *this->_dequePairs.size()); \
			i++)
			tempJacob.push_back(tempJacob[i - 1] + (2 * tempJacob[i - 2]));
	}
	return (tempJacob);
}

void PmergeMe::binarySearchDeque(long number)
{
	int start, mid, end;

	start = 0;
	end = this->_dequeOrganized.size();

	while(start < end)
	{
		mid = start + (end - start) / 2;
		if (number >= this->_dequeOrganized[mid])
			start = mid + 1;
		else if (number < this->_dequeOrganized[mid])
			end = mid;
	}
	this->_dequeOrganized.insert(this->_dequeOrganized.begin() + start, number);
}

//------------------------------------//
//              VECTOR                //
// -----------------------------------//


void PmergeMe::organizeVector(void)
{
	// Phase 1
	splitIntoPairsVector();
	if (this->_vector.size() == 1)
	{
		this->_vectorOrganized.push_back(this->_vector[0]);
		return ;
	}

	// Phase 2
	organizePairsVector();
	//printPairsVector(this->_vectorPairs); //DEBUG

	// Phase 3
	organizePairVectorRecursively(this->_vectorPairs);
	//std::cout << "\nFASE 3" << "\n";
	//printPairsVector(this->_vectorPairs); //DEBUG

	// Put the biggest numbers in the _vectorOrganized
	for (std::vector<std::pair<long, long> >::iterator it = _vectorPairs.begin(); it != _vectorPairs.end(); it++)
		_vectorOrganized.push_back(it->second);

	//std::cout << "\nVector atual, fase 3: ";
	//printVector(this->_vectorOrganized); //DEBUG

	// Phase 4
	putSmallestNumberinVector();
	//std::cout << "\nVector atual, fase 4: ";
	//printVector(this->_vectorOrganized); //DEBUG

	// Phase 5
	putTheRestVector();
	//std::cout << "\nVector atual, fase 5: ";
	//printVector(this->_vectorOrganized); //DEBUG
}

// -- PHASE 1 -- //
void PmergeMe::splitIntoPairsVector(void)
{
	for (size_t i = 0; i < this->_vector.size(); i += 2)
	{
		if (i + 1 < this->_vector.size())
			this->_vectorPairs.push_back(std::make_pair(this->_vector[i], this->_vector[i + 1]));
		else
		{
			this->_oddVector = true;
			this->_vectorLastElement = this->_vector[i];
		}
	}
}

// -- PHASE 2 -- //
void PmergeMe::organizePairsVector(void)
{
	for (size_t i = 0; i < _vectorPairs.size(); i++)
	{
		if (_vectorPairs[i].second < _vectorPairs[i].first)
			std::swap(_vectorPairs[i].first, _vectorPairs[i].second);
	}
}

// -- PHASE 3 -- //
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
	
	// Check if is in the end of the pairs
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

// -- PHASE 4 -- //
void PmergeMe::putSmallestNumberinVector(void)
{
	this->_vectorOrganized.insert(this->_vectorOrganized.begin(), this->_vectorPairs[0].first);
}

// -- PHASE 5 -- //
void PmergeMe::putTheRestVector(void)
{
	std::vector<long> jacob;
	
	jacob = createJacobVector();
	//std::cout << "\nJACOB: ";
	//printVector(jacob); // DEBUG

	for (size_t i = 1; i < jacob.size(); i++)
	{
		for (size_t j = jacob[i]; (long)j > jacob[i - 1]; j--)
		{
			if (j >= this->_vectorPairs.size())
			{
				if (this->_vectorPairs.size() == 1 && this->_oddVector == true)
					binarySearchVector(this->_vectorLastElement);
				continue;
			}
			binarySearchVector(this->_vectorPairs[j].first);
			if(this->_vectorOrganized.size() == (2 *(_vectorPairs.size())))
			{
				if (this->_oddVector == true)
					binarySearchVector(this->_vectorLastElement);
				return ;
			}
		}
	}
}


// ----------------- VECTOR HELPERS ------------------- //


void PmergeMe::printVector(std::vector<long> vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << "\n";
}

void PmergeMe::printPairsVector(std::vector<std::pair<long, long> > &pair)
{
	for (size_t i = 0; i < pair.size(); i++)
		std::cout << "(" << pair[i].first << ", " << pair[i].second << ") ";
	if (this->_vector.size() % 2 != 0)
		std::cout << "(" << this->_vectorLastElement << ", NONE)";
	std::cout << "\n";
}

void PmergeMe::argsToVector(int ac, char **av)
{
	for (int i = 1; i < ac; i++)
	{
		if (std::strtol(av[i], NULL, 0) > MAX_INT || std::strtol(av[i], NULL, 0) < MIN_INT)
			throw std::runtime_error("Syntax Error! Number overflow!");
		else
			this->_vector.push_back(std::strtol(av[i], NULL, 0));
	}
}

std::vector<long> PmergeMe::createJacobVector(void)
{
	std::vector<long> tempJacob;

	if (this->_vectorPairs.size() == 0)
		tempJacob.push_back(0);
	else if (this->_vectorPairs.size() == 1)
	{
		tempJacob.push_back(0);
		tempJacob.push_back(1);
	}
	else
	{
		tempJacob.push_back(0);
		tempJacob.push_back(1);

		for (size_t i = 2; \
			static_cast<size_t>(tempJacob[i - 1] + 2 * tempJacob[i - 2]) < (2 *this->_vectorPairs.size()); \
			i++)
			tempJacob.push_back(tempJacob[i - 1] + (2 * tempJacob[i - 2]));
	}
	return (tempJacob);
}

void PmergeMe::binarySearchVector(long number)
{
	int start, mid, end;

	start = 0;
	end = this->_vectorOrganized.size();

	while(start < end)
	{
		mid = start + (end - start) / 2;
		if (number >= this->_vectorOrganized[mid])
			start = mid + 1;
		else if (number < this->_vectorOrganized[mid])
			end = mid;
	}
	this->_vectorOrganized.insert(this->_vectorOrganized.begin() + start, number);
}



std::vector<long> PmergeMe::getOrganizedVector(void)
{
	return this->_vectorOrganized;
}

std::deque<long> PmergeMe::getOrganizedDeque(void)
{
	return this->_dequeOrganized;
}

PmergeMe::PmergeMe()
{
	this->_oddDeque = false;
	this->_oddVector = false;
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