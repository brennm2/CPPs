/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:05:50 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/18 18:53:48 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

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

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

static long int MAX_INT = std::numeric_limits<int>::max();
static long int MIN_INT = std::numeric_limits<int>::min();


class RPN
{
private:
	std::stack <long int> _numberStack;
public:

	void calculation(std::string str);
	bool isValidNumber(std::string input);
	bool isValidOperator(std::string input);

	RPN();
	~RPN();
	RPN(const RPN &copy);
	RPN &operator=(const RPN &copy);
} ;

#endif