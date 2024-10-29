/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:57:34 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 17:47:36 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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

class Animal
{
protected:
	std::string _type;
public:
	virtual	void	makeSound(void) const;
	std::string getType(void) const;
	
	Animal();
	virutal ~Animal();
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
} ;


#endif