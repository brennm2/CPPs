/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:37:19 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/11 16:21:45 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_HPP
#define MutantStack_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <list>

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	~MutantStack();
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &copy);

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
} ;

#endif