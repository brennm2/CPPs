/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 13:06:08 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/07 15:10:29 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef easyfind_HPP
#define easyfind_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


class NoMatch : public std::exception
{
	const char* what() const throw();
};

const char* NoMatch::what() const throw()
{
	return "Error: No match has been found!";
}

template <typename T>
typename T::iterator easyFind(T& container, int number)
{
	for (typename T::iterator i = container.begin(); i != container.end(); ++i)
	{
		if (*i == number)
			return i;
	}
	throw NoMatch();
}



#endif