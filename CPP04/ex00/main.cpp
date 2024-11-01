/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:54:00 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/01 13:52:02 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "This animal is: " << j->getType() << " " << std::endl;
	std::cout << "This animal is: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n";
	std::cout << green << "--- Wrong Animal ---" << reset << "\n";
	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();
	const WrongCat *wronger = new WrongCat();
	std::cout << "This animal is: " << wrong->getType() << "\n";
	std::cout << "This animal is: " << wrongCat->getType() << "\n";
	std::cout << "This animal is: " << wronger->getType() << "\n";
	wrongCat->makeSound();
	wrong->makeSound();
	wronger->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrong;
	delete wrongCat;
	delete wronger;

}