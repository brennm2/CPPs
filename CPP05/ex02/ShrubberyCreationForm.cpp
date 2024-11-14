/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:56:00 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/14 17:29:17 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default", 150, 150 , "Default")
{
	std::cout << magenta << "ShrubberyCreationForm Default Constructor Called\n" << reset;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newName, int newGradeToSign, int newGradeToExecute, std::string newTarget)
	: AForm(newName, newGradeToSign, newGradeToExecute , "Default")
{
	std::cout << magenta << "ShrubberyCreationForm Name Constructor Called\n" << reset;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << red << "ShrubberyCreationForm Destructor Called\n" << reset;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	std::cout << cyan << "ShrubberyCreationForm Copy Constructor Called\n" << reset;
	this->HERE = copy.HERE;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << cyan << "ShrubberyCreationForm Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->HERE = copy.HERE;
	}
	return (*this);
}