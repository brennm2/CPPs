/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:14:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/24 12:01:36 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>


class Dog : public Animal
{
private:
	
public:
	void	makeSound(void) const;

	Dog();
	~Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
} ;

#endif