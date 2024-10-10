/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:50:38 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/10 15:19:48 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

class HumanB
{
private:
	Weapon	*_Weapon;
	std::string	_name;


public:
	void	attack(void);
	void	setWeapon(Weapon &start_weapon);
	HumanB(std::string Name, Weapon &start_weapon);
	HumanB(std::string Name);
};

#endif