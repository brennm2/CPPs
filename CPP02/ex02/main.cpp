/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:24:07 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/15 18:24:00 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;

	//------------------//
	std::cout << "\n";
	if (a > b)
		std::cout << "A > B\n";
	else
		std::cout << "B > A\n";

	//------------------//
	std::cout << "\n";
	Fixed c(5);
	Fixed d(5);

	if (c == d)
		std::cout << "C == D\n";
	
	if (c >= d++)
		std::cout << "C >= D\n";

	if (c >= d)
		std::cout << "C >= D\n";
	else
		std::cout << "No :c\n";
	
	if (c <= d)
		std::cout << "C <= D\n";
	else
		std::cout << "No :c\n";

	if (c != d)
		std::cout << "Yes!\n";
	else
		std::cout << "No :c\n";
	

	return 0;
}
