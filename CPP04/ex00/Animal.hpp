/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:57:34 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/23 18:55:49 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

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

class Animal
{
protected:
	std::string _type;
public:
	virtual	void	makeSound(void);
	std::string getType(void);
	
	Animal();
	~Animal();
	Animal(const Animal &copy);
	Animal &operator=(const Animal &copy);
} ;


#endif