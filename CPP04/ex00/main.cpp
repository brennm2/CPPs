/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:54:00 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/23 18:57:28 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"


int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	//const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	//std::cout << i->getType() << " " << std::endl;
	//i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound()
}