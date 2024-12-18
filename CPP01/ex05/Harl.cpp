/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:07:41 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/14 11:14:22 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << green << "[DEBUG] " << reset << "Everything is fine right now!\n";
}

void	Harl::info(void)
{
	std::cout << blue << "[INFO] " << reset << "Okay, what is this? Kinda funny\n";
}

void	Harl::warning(void)
{
	std::cout << yellow << "[WARNING] " << reset << "Something is wrong, I think...\n";
}

void	Harl::error(void)
{
	std::cout << red << "[ERROR] " << reset << "It broke, RIP!\n" ;
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
	}
	std::cout << magenta << "[NOTHING] " << reset <<"Harl has nothing to say :O\n";
}

Harl::Harl()
{
}

Harl::~Harl()
{
}