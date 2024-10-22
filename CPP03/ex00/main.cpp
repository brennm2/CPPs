/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:27:54 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/22 12:02:41 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
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