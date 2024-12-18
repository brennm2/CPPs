/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:41:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/18 14:43:44 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	BitcoinExchange Bitcoin;

	if (ac == 2)
	{
		if (!Bitcoin.readTheFileToDataBase())
			return 0;
		Bitcoin.readInput(av[1]);
	}
	
}