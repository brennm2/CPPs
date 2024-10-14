/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:07:41 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/14 11:41:56 by bde-souz         ###   ########.fr       */
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
	
	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			(this->*func_ptr[0])();
		case 1:
			(this->*func_ptr[1])();
		case 2:
			(this->*func_ptr[2])();
		case 3:
			(this->*func_ptr[3])();
			return ;
	}
	std::cout << magenta << "[NOTHING] " << reset <<"Probably complaining about insignificant problems\n";
}

Harl::Harl()
{
}

Harl::~Harl()
{
}