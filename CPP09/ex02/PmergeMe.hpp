/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:01:54 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/09 18:39:28 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <limits>
#include <vector>
#include <deque>
#include <ctime>


// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

class PmergeMe 
{
private:

	// Vector
	bool	_oddVector;
	std::vector<long> _vector;
	std::vector<long> _vectorOrganized;
	std::vector<std::pair<long, long> > _vectorPairs;
	long _vectorLastElement;

	
	// Deque
	bool	_oddDeque;
	std::deque<long> _deque;
	std::deque<long> _dequeOrganized;
	std::deque<std::pair<long, long> > _dequePairs;
	long _dequeLastElement;
	
public:
	
	// Vector ------------------------- //
	void argsToVector(int ac, char **av);
	void organizeVector(void);
	void splitIntoPairsVector(void);
	void organizePairsVector(void);
	void organizePairVectorRecursively(std::vector<std::pair<long, long> > &pairs);
	void putSmallestNumberinVector(void);
	void putTheRestVector(void);
	void binarySearchVector(long number);
	std::vector<long> createJacobVector(void);

	//			--Print--
	void printVector(std::vector<long> vec);
	void printPairsVector(std::vector<std::pair<long, long> > &pair);
	

	// --------------------------------- //
	
	// Deque --------------------------- //
	void argsToDeque(int ac, char **av);
	void organizeDeque(void);
	void splitIntoPairsDeque(void);
	void organizePairsDeque(void);
	void organizePairDequeRecursively(std::deque<std::pair<long, long> > &pairs);
	void putSmallestNumberinDeque(void);
	void putTheRestDeque(void);
	std::deque<long> createJacobDeque(void);
	void binarySearchDeque(long number);



	void printPairsDeque(std::deque<std::pair<long, long> > &pair);
	void printDeque(std::deque<long> vec);

	// --------------------------------- //


	std::vector<long> getOrganizedVector(void);
	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &copy);
} ;

#endif