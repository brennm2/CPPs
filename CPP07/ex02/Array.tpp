/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:03:56 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/04 14:33:22 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_size);
}

template <typename T>
Array<T>::Array() : _array(new T[0]), _size(0)
{
	std::cout << magenta << "Array Default Constructor Called\n" << reset;
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n)
{
	std::cout << magenta << "Array size Constructor Called\n" << reset;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << red << "Array Destructor Called\n" << reset;
	delete[] this->_array;
}

template <typename T>
Array<T>::Array(const Array &copy)
	: _array(new T[copy._size]), _size(copy._size)
{
	std::cout << cyan << "Array Copy Constructor Called\n" << reset;
	for (unsigned int i = 0; i < _size; i++)
	{
		this->_array[i] = copy._array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
	std::cout << cyan << "Array Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		delete[] this->_array;
		this->_array = new T[copy.size];
		for (unsigned int i = 0; i < copy._size; i++)
		{
			this->_array[i] = copy._array[i];
		}

		this->_size = copy._size;
	}
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= this->_size)
	{
		throw OutOfBounds();
	}
	else
		return (this->_array[i]);
}

template <typename T>
const char* Array<T>::OutOfBounds::what() const throw()
{
	return "Error: index out of bounds!";
}