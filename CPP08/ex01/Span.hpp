/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:06:07 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 18:39:22 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Span_HPP
#define Span_HPP

#include <iostream>
#include <string>
#include <vector>

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


class Span 
{
private:
	unsigned int _N;
	unsigned int _currentN;
	std::vector<int> _vec;

public:
	void addNumber(int number);
	void printVec(void);

	Span();
	Span(unsigned int number);
	~Span();
	Span(const Span &copy);
	Span &operator=(const Span &copy);
} ;

class NoSpaceLeft : public std::exception
{
	const char* what() const throw();
};



#endif