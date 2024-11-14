/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 12:01:28 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/14 16:52:59 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *Zombie_array;
	
	Zombie_array = zombieHorde(5, "foo");
	
	for(int i = 0; i < 5; i++)
	{
		std::cout << "Zombie " << yellow << i << reset << " ";
		Zombie_array[i].announce();
	}
	delete[] Zombie_array;
}