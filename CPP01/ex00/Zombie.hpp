/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:59:52 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/10 11:56:40 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


// COLORS //
#include <iostream>
#include <string>
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

class Zombie
{
private:
	std::string	_name;
	
public:
	void announce();
	Zombie(std::string name);
	~Zombie();
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );


#endif