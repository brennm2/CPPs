/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:12:41 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/17 11:22:17 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

// COLORS //
#include <iostream>
#include <string>
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

class Fixed
{
	private:
		int _integer;
		static const int _static_integer = 8;
	
	public:
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		
		Fixed();
		Fixed(const int Number);
		Fixed(const float Number);
		~Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);

		//New Ones
		//Comparision Operators
		bool operator<(const Fixed &copy);
		bool operator>(const Fixed &copy);
		bool operator>=(const Fixed &copy);
		bool operator<=(const Fixed &copy);
		bool operator==(const Fixed &copy);
		bool operator!=(const Fixed &copy);

		//Arithmetic Operators
		Fixed operator+(const Fixed &copy);
		Fixed operator-(const Fixed &copy);
		Fixed operator*(const Fixed &copy);
		Fixed operator/(const Fixed &copy);

		//Increment/Decrement Operators
		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		//Public Overloaded
		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
		
} ;

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif