/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:18:42 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/01 14:24:53 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
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

class AMateria
{
protected:
	std::string _type;
public:
	std::string const & getType() const;
 	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	
	AMateria(std::string const & type);
	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria &copy);
	AMateria &operator=(const AMateria &copy);
};


#endif