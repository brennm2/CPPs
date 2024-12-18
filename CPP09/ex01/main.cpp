/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:31:07 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/18 17:08:55 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	RPN Stack;
	if (ac == 2)
	{
		try
		{
			Stack.calculation(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << red << "Error: "<< e.what() << '\n' << reset;
		}
	}
	else
	{
		std::cout << "ERROR WITH ARGUMENTS" << "\n";
	}
}