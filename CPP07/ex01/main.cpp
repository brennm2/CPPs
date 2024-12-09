/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:14:42 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 11:22:43 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	addOne(int number)
{
	int tempNumber = number + 1;

	std::cout << "addOne: " << tempNumber << "\n";
}

void	toUpperPrint(const char c)
{
	std::cout << static_cast<char>(toupper(c)) << "\n";
}

int main( void )
{
	int arrayInt[] = {1, 2, 3, 4, 5};
	int arrayChar[] = {'a', 'b', 'c', 'd', 'f'};

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Int Tester" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	iter(arrayInt, 5, addOne);

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "String Tester" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	iter(arrayChar, 5, toUpperPrint);

}


