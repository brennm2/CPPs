/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:31:07 by bde-souz          #+#    #+#             */
/*   Updated: 2025/01/22 13:14:58 by bde-souz         ###   ########.fr       */
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
		std::cout << red << "Problem with arguments!" << "\n" << reset;
	}
}