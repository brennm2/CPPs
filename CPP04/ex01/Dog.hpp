/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:14:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 17:44:33 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"
#include <iostream>
#include <string>


class Dog : public Animal
{
private:
	Brain *_brain;
public:
	void	makeSound(void) const;
	void	think(unsigned int number);
	void	setIdeias(unsigned int index, std::string idea);

	Dog();
	~Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
} ;

#endif