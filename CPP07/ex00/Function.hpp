/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Function.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:54:38 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/03 15:42:40 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Function_HPP
#define Function_HPP

#include <iostream>
#include <string>

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

template <typename T>
T find_max(T a, T b)
{
	if (a > b)
		return a;
	else
		return b;
}

template <typename T>
T find_min(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}

template <typename T>
void swap(T &a, T &b)
{
	T tempT = a;
	a = b;
	b = tempT;
}


#endif