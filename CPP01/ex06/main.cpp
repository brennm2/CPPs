/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:05:21 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/14 11:45:56 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	switch (ac)
	{
		case 1:
			std::cout << "You must have something to complain!\n";
			return (1);
		case 2:
			Harl HarlComplainer;
			HarlComplainer.complain(av[1]);
			return (0);
	}
	std::cout << "You complain too mutch!\n";
	return (1);
}