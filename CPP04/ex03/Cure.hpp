/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:34:41 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/31 15:27:58 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
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

class Cure : public AMateria
{
protected:
	
public:
 	AMateria* clone() const;
	void use(ICharacter& target);

	Cure();
	~Cure();
	Cure(const Cure &copy);
	Cure &operator=(const Cure &copy);
}	;


#endif