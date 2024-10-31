/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:33:11 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/31 17:55:42 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void	MateriaSource::search_and_place(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if(this->_materiaBackLog[i] == NULL)
		{
			this->_materiaBackLog[i] = m;
			std::cout << cyan << "Spell " << red << m->getType() << cyan
			<< " learned and placed at page: " << red 
			<< i + 1 << "\n" << reset;
			this->_backLogIndex++;
			return ;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (this->_backLogIndex < 4)
		this->search_and_place(m);
	else
	{
		std::cout << cyan << "\nNo more pages to be able to learn!\n" << reset;
		delete m;
		std::cout << "\n";
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaBackLog[i] != NULL && this->_materiaBackLog[i]->getType() == type)
		{
			AMateria *temp = this->_materiaBackLog[i]->clone();
			delete this->_materiaBackLog[i];
			this->_materiaBackLog[i] = NULL;
			this->_backLogIndex--;
			std::cout << cyan << "Spell " << red << temp->getType() 
			<< cyan " created!\n";
			return (temp);
		}
	}
	std::cout << red << "\nNo spells were found in the book!\n\n" << reset;
	return (0);
}



MateriaSource::MateriaSource() : IMateriaSource()
{
	//std::cout << magenta << "MateriaSource Default Constructor Called\n" << reset;
	for (int i = 0; i < 4; i++)
		this->_materiaBackLog[i] = NULL;
	this->_backLogIndex = 0;
}

MateriaSource::~MateriaSource()
{
	std::cout << red << "MateriaSource Destructor Called\n" << reset;
	for (int i = 0; i < 4; i++)
	{
		if (this->_materiaBackLog[i] != NULL)
			delete this->_materiaBackLog[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &copy) : IMateriaSource(copy)
{
	// std::cout << cyan << "MateriaSource Copy Constructor Called\n" << reset;
	for (int i = 0; i < 4; i++)
		this->_materiaBackLog[i] = NULL;
	*this = copy;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
	// std::cout << cyan << "MateriaSource Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->_materiaBackLog[i])
			{
				delete _materiaBackLog[i];
				this->_materiaBackLog[i] = copy._materiaBackLog[i]->clone();
			}
		}
	}
	return (*this);
}