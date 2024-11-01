/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:05:01 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/01 14:40:14 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const &Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << red << "\nMateria don't exist!\n\n" << reset;
		return ;
	}
	if (_indexPos < 4)
	{
		this->_speelbook[_indexPos] = m->clone();
		std::cout << cyan << " --- Spell " << red << m->getType() 
		<< cyan " equiped! --- \n" << reset;
		this->_indexPos++;
		delete m ;
		//this->_garbageIndexPos--
	}
	else
		std::cout << red << "\nNo more pages in the Speel Book!\n\n" << reset;
}

void Character::unequip(int idx)
{
	if (idx < 1 || idx > 4)
	{
		std::cout << red << "\nWrong index!\n\n" << reset;
		return ;
	}
	else if (!this->_speelbook[idx - 1])
	{
		std::cout << red << "\nNo spell in this page!\n\n" << reset;
		return ;
	}
	else
	{
		this->_garbageSpeel[_garbageIndexPos] = this->_speelbook[idx - 1];
		this->_speelbook[idx - 1] = NULL;
		std::cout << "Unequiped the " << yellow
		<< this->_garbageSpeel[_garbageIndexPos++]->getType() << " speel!\n" << reset;
		this->_indexPos--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 1 || idx > 4)
	{
		std::cout << red << "Wrong index!\n" << reset;
		return ;
	}
	else if (!this->_speelbook[idx - 1])
	{
		std::cout << red << "\nNo spell in this page!\n\n" << reset;
		return ;
	}
	else
	{
		this->_speelbook[idx - 1]->use(target);
	}
}


Character::Character() : ICharacter()
{
	std::cout << magenta << "Character Default Constructor Called\n" << reset;
	for (int i = 0; i < 4; i++)
		this->_speelbook[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_garbageSpeel[i] = NULL;
	this->_name = "default";
	this->_garbageIndexPos = 0;
	this->_indexPos = 0;
}

Character::Character(std::string newName) : ICharacter()
{
	std::cout << magenta << "Character " << newName << " Constructor Called\n" << reset;
	for (int i = 0; i < 4; i++)
		this->_speelbook[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_garbageSpeel[i] = NULL;
	this->_name = newName;
	this->_garbageIndexPos = 0;
	this->_indexPos = 0;
}

Character::~Character()
{
	std::cout << red << "Character Destructor Called\n" << reset;
	for (int i = 0; i < 4; i++)
	{
		if (this->_speelbook[i])
			delete this->_speelbook[i];
	}
	for (int i = 0; i < 100; i++)
	{
		if (this->_garbageSpeel[i])
			delete this->_garbageSpeel[i];
	}
}

Character::Character(const Character &copy) : ICharacter(copy)
{
	std::cout << cyan << "Character Copy Constructor Called\n" << reset;
	for (int i = 0; i < 4; i++)
		this->_speelbook[i] = NULL;
	for (int i = 0; i < 100; i++)
		this->_garbageSpeel[i] = NULL;
	*this = copy;
}

Character &Character::operator=(const Character &copy)
{
	std::cout << cyan << "Character Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		for(int i = 0; i < 4; i++)
		{
			if (this->_speelbook[i])
			{
				delete _speelbook[i];
				this->_speelbook[i] = copy._speelbook[i]->clone();
			}
		}
	}
	return (*this);
}