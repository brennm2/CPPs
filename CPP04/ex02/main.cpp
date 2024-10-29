/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:54:00 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 19:47:37 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main(void)
{
	//Animal test;
	
	{
		int array_size = 10;
		Animal *animals[array_size];
		
		for (int i = 0; i < 5; i++) //dogs
			animals[i] = new Dog();
		for (int i = 5; i < 10; i++) //cat
			animals[i] = new Cat();
		for (int i = 0; i < 10; i++) //make sound
			animals[i]->makeSound();

		for (int i = 0; i < 10; i++) //type
		{
			if (i != 9)
				std::cout << i + 1 << " - " << animals[i]->getType() << ", ";
			else 
				std::cout << i + 1 << " - " << animals[i]->getType() << "\n";
		}

		//deleting
		for (int i = 0; i < 10; i++) 
		{
			delete animals[i];
		}
	}

	std::cout << cyan << "\n\n ---- Separated animals (DOG) ----\n\n" << reset;
	{
		Dog *dog1 = new Dog;

		dog1->setIdeias(1, "Ola mundo");

		Dog *dog2 = new Dog;
		Dog *dog3 = new Dog(*dog1);
		dog1->setIdeias(2, "Hello World!");
		
		*dog2 = *dog1;
		delete dog1;

		std::cout << "Dog2 thinking\n";
		dog2->think(5);

		std::cout << "Dog3 thinking\n";
		dog3->think(5);

		delete dog2;
		delete dog3;
	}

		std::cout << cyan << "\n\n ---- Separated animals (CAT) ----\n\n" << reset;
	{
		Cat *cat1 = new Cat;

		cat1->setIdeias(1, "Ola mundo");

		Cat *cat2 = new Cat;
		Cat *cat3 = new Cat(*cat1);
		cat1->setIdeias(2, "Hello World!");
		
		*cat2 = *cat1;
		delete cat1;

		std::cout << "Cat2 thinking\n"; //Copy
		cat2->think(5);

		std::cout << "Cat3 thinking\n"; //Duplicated
		cat3->think(5);

		delete cat2;
		delete cat3;
	}
	
}

