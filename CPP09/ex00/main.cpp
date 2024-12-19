/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:41:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/19 11:21:23 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	BitcoinExchange Bitcoin;

	if (ac == 2)
	{
		try
		{
			Bitcoin.readTheFileToDataBase();
			Bitcoin.readInput(av[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << red << "Error: " << e.what() << '\n' << reset;
		}
	}
	else
	{
		std::cerr << red << "Wrong arguments (" << av[0] << \
		" filename.txt)" << "\n" << reset;
	}
}