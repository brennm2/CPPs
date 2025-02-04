/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:49:59 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/26 12:12:42 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << red << "Error, no argument!" << "\n" << reset;
	else if (ac == 2)
		ScalarConverter::converter(av[1]);
	else
		std::cout << red << "Only one argument is valid!" << reset <<"\n";
}