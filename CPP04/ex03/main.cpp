/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:18:53 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/01 14:48:19 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	{
		std::cout << yellow << "\n|------------------|\n";
		std::cout << "|----- TEST 1 -----|\n";
		std::cout << "|------------------|\n\n" << reset;


		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice()); // Learning new spell

		ICharacter* me = new Character("me");
		AMateria* tmp;

		tmp = src->createMateria("cure"); // Trying to create a spell that don't exist (needs to return 0)
		me->equip(tmp); // Equipping NULL spell

		tmp = src->createMateria("ice"); // Creating a spell that exist
		me->equip(tmp); // Equipping spell

		
		ICharacter* bob = new Character("bob");
		me->use(1, *bob); // Using spell [1] (index 0)
		me->use(2, *bob); // Trying to use spell 2 that don't exist (index 1)

		src->learnMateria(new Cure()); // Learning new spell
		tmp = src->createMateria("cure"); // Creating spell
		me->equip(tmp); // Using this spell
		me->use(2, *bob); // Trying again to use spell [2] (Index 0)


		delete bob;
		delete me;
		delete src;
	}
	
	
	{
		std::cout << yellow << "\n|------------------|\n";
		std::cout << "|----- TEST 2 -----|\n";
		std::cout << "|------------------|\n\n" << reset;


		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice()); // Learning new spell

		// -- Creating more than 4 pages --
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Ice());
		// -- Creating more than 4 pages --

		ICharacter	*you = new Character("you");
		ICharacter	*bob = new Character("Bob");
	

		std::cout << yellow << "\n|----- USING THE SPEEL BOOK -----|\n\n" << reset;

		you->equip(src->createMateria("ice")); // Creating one Ice spell and equipping it
		src->learnMateria(new Ice()); // Learning new spell and putting on available spot
	
		std::cout << "\n\n\n";
		you->equip(src->createMateria("cure")); // Creating one Cure spell and equipping it
		src->learnMateria(new Ice()); // Learning new spell and putting on available spot


		you->equip(src->createMateria("lol")); // Trying to use a spell that don't exist

		you->use(3, *bob); // Using a page that don't have any spell

		
		std::cout << yellow << "\n|----- USING THE ALL THE SPELLS -----|\n\n" << reset;

		you->equip(src->createMateria("ice"));
		you->equip(src->createMateria("ice"));
		you->use(1, *bob);
		you->use(2, *bob);
		you->use(3, *bob);
		you->use(4, *bob);
	
		std::cout << "\n";
		you->unequip(4); // Unequip spell 4
		you->use(4, *bob); // Trying to use spell 4 (no spell)
		you->equip(src->createMateria("ice")); // Creating one Ice spell and equipping it
		you->use(4, *bob); // Trying to use spell 4 (with spell)
		you->unequip(4); // Unequip spell 4
		you->use(4, *bob); // Trying to use spell 4 (no spell)


		std::cout << "\n";
		delete src;
		delete you;
		delete bob;
	}
}