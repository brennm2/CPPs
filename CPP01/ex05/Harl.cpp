/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:07:41 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/11 17:09:47 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "Everything is fine right now!\n";
}

void	Harl::info(void)
{
	std::cout << "Okay, what is this? Kinda funny\n";
}

void	Harl::warning(void)
{
	std::cout << "Something is wrong, I think...\n";
}

void	Harl::error(void)
{
	std::cout << red << "It broked, RIP!\n" << reset;
}

void	Harl::complain(std::string level)
{
	void (Harl::*func_ptr[])() = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*func_ptr[i])();
			return ;
		}
		i++;
	}
}

Harl::Harl()
{
}

Harl::~Harl()
{
}