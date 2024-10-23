/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:14:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/23 18:57:14 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>
#include <string>

// COLORS //
#define blue "33[34m"
#define red "33[31m"
#define green "33[32m"
#define yellow "33[33m"
#define magenta "33[35m"
#define cyan "33[36m"
#define reset "33[0m"


class Dog : public Animal
{
private:
	
public:
	void	makeSound(void);
	std::string getType(void);

	Dog();
	~Dog();
	Dog(const Dog &copy);
	Dog &operator=(const Dog &copy);
} ;

#endif