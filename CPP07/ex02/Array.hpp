/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:21:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/04 14:00:18 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
#define Array_HPP

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
class Array
{
private:
	T *_array;
	unsigned int _size;

public:

	T &operator[](unsigned int i);
	unsigned int size(void) const;

	Array();
	Array(unsigned int n);
	~Array();
	Array(const Array &copy);
	Array &operator=(const Array &copy);

	class OutOfBounds : public std::exception
	{
		const char* what() const throw();
	};
} ;




#endif