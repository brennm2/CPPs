/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:37:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/11 16:56:00 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	//std::cout << magenta << "MutantStack Default Constructor Called\n" << reset;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	// std::cout << red << "MutantStack Destructor Called\n" << reset;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
	// std::cout << cyan << "MutantStack Copy Constructor Called\n" << reset;
	*this = copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
	// std::cout << cyan << "MutantStack Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		std::stack<T>::operator=(copy);
	}
	return (*this);
}
