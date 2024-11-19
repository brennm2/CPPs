/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:56:00 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 13:25:25 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"


void	ShrubberyCreationForm::executor() const
{
	std::string	fileName = (this->getTarget() + "_shrubbery");
	std::ofstream outputFile(fileName.c_str());
	if (outputFile.fail())
	{
		std::cout << red << "Error when creating a Shrubbery file!" << "\n" << reset;
		return ;
	}
	else
	{
		outputFile << "       ###\n";
		outputFile << "      #o###\n";
		outputFile << "    #####o###\n";
		outputFile << "   #o#\\#|#/###\n";
		outputFile << "    ###\\|/#o#\n";
		outputFile << "     # }|{  #\n";
		outputFile << "       }|{\n";
		outputFile.close();
		std::cout << green << "File " << red << this->getTarget() \
		<< green << " created!" << "\n" << reset;
	}
}

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Default", 145, 137 , "Default")
{
	std::cout << magenta << "ShrubberyCreationForm Default Constructor Called\n" << reset;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
	: AForm("Shrubbery", 145, 137 , newTarget)
{
	std::cout << magenta << "ShrubberyCreationForm Target Constructor Called\n" << reset;
}


ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << red << "ShrubberyCreationForm Destructor Called\n" << reset;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
	: AForm(copy)
{
	std::cout << cyan << "ShrubberyCreationForm Copy Constructor Called\n" << reset;
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << cyan << "ShrubberyCreationForm Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}