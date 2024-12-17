/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:41:04 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/17 17:44:39 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	BitcoinExchange Bitcoin;

	if (ac == 2)
	{
		//Bitcoin.readTheFileToDataBase();
		Bitcoin.readInput(av[1]);
		// for (std::map<std::string, float>::iterator i = Bitcoin.database.begin(); 
		// 	i != Bitcoin.database.end(); ++i)
		// {
		// 	std::cout << i->first << " - " << i->second << "\n";
		// }
		// int tempI = 0;
		// std::cout << "size: " << Bitcoin.input.size() << "\n";
		// for (std::map<std::string, float>::iterator i = Bitcoin.input.begin();
		// 	i != Bitcoin.input.end(); ++i)
		// {
		// 	tempI++;
		// 	std::cout << i->first << " " << i->second << "\n";
		// 	std::cout << "LINE: " << tempI << "\n";
		// }
	}
}