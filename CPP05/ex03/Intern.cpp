/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:17:19 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 17:44:46 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm *Intern::makePresidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	const std::string formtypes[3] = {"shrubbery request", \
								"robotomy request", \
								"presidential request"};
	AForm *(Intern::*forms[])(const std::string) = {
		&Intern::makeShrubbery,
		&Intern::makeRobotomy,
		&Intern::makePresidential};
	
	for (int i = 0; i < 3; i++)
	{
		if (formtypes[i] == formName)
		{
			AForm *formTemp = (this->*forms[i])(target);
			std::cout << green << "Intern created " \
				<< red << formTemp->getName() << "\n" << reset;
			return (formTemp);
		}
	}
	std::cout << yellow <<  "No form was been found!" << "\n" << reset;
	return(NULL);
}



Intern::Intern()
{
	std::cout << magenta << "Intern Default Constructor Called\n" << reset;
}

Intern::~Intern()
{
	std::cout << red << "Intern Destructor Called\n" << reset;
}

Intern::Intern(const Intern &copy)
{
	(void)copy;
	std::cout << cyan << "Intern Copy Constructor Called\n" << reset;
}

Intern &Intern::operator=(const Intern &copy)
{
	std::cout << cyan << "Intern Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}