/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:27:54 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/23 15:22:12 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << cyan << "\n---- ClapTrap ----\n" << reset;
	{
		ClapTrap Clap1("Clap");

		Clap1.attack("Mordecai");
		std::cout << yellow << "Energy: " << Clap1.getEnergy() << "\n" << reset;
		Clap1.takeDamage(5);
		Clap1.takeDamage(4);
		std::cout << yellow << "Hp: " << Clap1.getHp() << "\n" << reset;
		Clap1.beRepaired(5);
		std::cout << yellow << "Hp: " << Clap1.getHp() << "\n" << reset;
		std::cout << yellow << "Energy: " << Clap1.getEnergy() << "\n" << reset;
		Clap1.takeDamage(10);
		Clap1.beRepaired(5);
		Clap1.attack("Me");
		Clap1.takeDamage(5);
	}

	std::cout << cyan << "\n---- ScavTrap ----\n" << reset;
	{
		ScavTrap Scav1("Scav");

		Scav1.attack("Krieg");
		std::cout << yellow << "Energy: " << Scav1.getEnergy() << "\n" << reset;
		Scav1.takeDamage(5);
		std::cout << yellow << "Hp: " << Scav1.getHp() << "\n" << reset;
		Scav1.beRepaired(50);
		std::cout << yellow << "Hp: " << Scav1.getHp() << "\n" << reset;
		std::cout << yellow << "Energy: " << Scav1.getEnergy() << "\n" << reset;
		Scav1.guardGate();
		Scav1.takeDamage(150);

		Scav1.guardGate();
		Scav1.attack("Me");
	}

	std::cout << cyan << "\n---- ScavTrap ----\n" << reset;
	{
		FragTrap Frag1("Frag");

		Frag1.attack("Lilith");
		Frag1.highFivesGuys();
		std::cout << yellow << "Energy: " << Frag1.getEnergy() << "\n" << reset;
		Frag1.takeDamage(50);
		std::cout << yellow << "Hp: " << Frag1.getHp() << "\n" << reset;
		Frag1.beRepaired(50);
		std::cout << yellow << "Hp: " << Frag1.getHp() << "\n" << reset;
		std::cout << yellow << "Energy: " << Frag1.getEnergy() << "\n" << reset;

		Frag1.takeDamage(150);
		Frag1.beRepaired(50);
		Frag1.highFivesGuys();
	}

	std::cout << cyan << "\n---- DiamondTrap ----\n" << reset;
	{
		DiamondTrap Diamond("Diamond");

		Diamond.whoAmI();
		Diamond.attack("Handsome Jack");
		Diamond.highFivesGuys();
		Diamond.guardGate();
		std::cout << yellow << "Energy: " << Diamond.getEnergy() << "\n" << reset;
		Diamond.takeDamage(50);
		std::cout << yellow << "Hp: " << Diamond.getHp() << "\n" << reset;
		Diamond.beRepaired(5);
		std::cout << yellow << "Hp: " << Diamond.getHp() << "\n" << reset;
		std::cout << yellow << "Energy: " << Diamond.getEnergy() << "\n" << reset;
		Diamond.takeDamage(50000000);
		Diamond.highFivesGuys();
		Diamond.guardGate();
	}
}


