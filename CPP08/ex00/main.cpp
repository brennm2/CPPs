/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:52:47 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/11 18:25:45 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	
	std::vector<int> vec;

	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << "vec: " << vec[i] << "\n";
	}

	try
	{
		std::vector<int>::iterator vecIter = easyFind(vec, 30);
		std::cout << "Found!: " << green << *vecIter << "\n" << reset;
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}

}