/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:26:49 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/26 17:25:57 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

void	Serialize::displayData(Data *ptr)
{
	std::cout << "Name: " << ptr->name << "\n";
	std::cout << "Age: " << ptr->age << "\n";
}

uintptr_t Serialize::serialize(Data* ptr)
{
	uintptr_t adress = reinterpret_cast<uintptr_t>(ptr);
	return (adress);
}

Data* Serialize::deserialize(uintptr_t raw)
{
	Data *tempData = reinterpret_cast<Data*>(raw);
	return (tempData);
}



void	Serialize::converter(Data* dataptr)
{
	Serialize	s;
	uintptr_t	tempInt;
	Data		*tempData;


	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Original Data to Int" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	tempInt = s.serialize(dataptr);
	std::cout << "Adress in int: " << tempInt << "\n";



	tempData = s.deserialize(tempInt);
	std::cout << "\n";
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Original Data" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	s.displayData(dataptr);

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "DeserializeData" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	s.displayData(tempData);

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Comparing the Original" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	std::cout << "Original Adress: " << dataptr << "\n";
	std::cout << "TempData Adress: " << tempData << "\n";


	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Change the values" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	dataptr->name = "Teste1";
	tempData->name = "Teste2";

	s.displayData(dataptr);
	s.displayData(tempData);

	std::cout << "\n";
}

Serialize::Serialize()
{
	// std::cout << magenta << "Serialize Default Constructor Called\n" << reset;
}

Serialize::~Serialize()
{
	// std::cout << red << "Serialize Destructor Called\n" << reset;
}

Serialize::Serialize(const Serialize &copy)
{
	// std::cout << cyan << "Serialize Copy Constructor Called\n" << reset;
	(void)copy;
}

Serialize &Serialize::operator=(const Serialize &copy)
{
	// std::cout << cyan << "Serialize Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}