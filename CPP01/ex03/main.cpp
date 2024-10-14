/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:56:43 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/14 11:50:36 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon axe("Axe");
		HumanA Bob("Bob", axe);
		
		Bob.attack();
		axe.setType("Fire Axe");
		Bob.attack();
	}
		std::cout << "\n";
	{
		Weapon knife("Knife");
		HumanB Scott("Scott");
	
		Scott.attack();
		std::cout << "Scott looted a " << knife.getType() << "\n";
		Scott.setWeapon(knife);

		Scott.attack();
		std::cout << "Scott Killed the bug! Weapon Powered up!\n";
		knife.setType("Eletric Knife");
		Scott.attack();
	}
}
