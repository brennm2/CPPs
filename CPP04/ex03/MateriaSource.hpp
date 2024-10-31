/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:33:07 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/31 15:31:03 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
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

class MateriaSource : public IMateriaSource
{
private:
	AMateria *_materiaBackLog[4];
	int		_backLogIndex;
public:
	void learnMateria(AMateria* m);
	AMateria* createMateria(std::string const &type);
	void	search_and_place(AMateria* m);

	MateriaSource();
	virtual ~MateriaSource();
	MateriaSource(const MateriaSource &copy);
	MateriaSource &operator=(const MateriaSource &copy);
};


#endif