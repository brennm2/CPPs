/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:34:14 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 14:09:45 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat Brendon("Brendon", 1);
	Bureaucrat Joao("Joao", 150);
	ShrubberyCreationForm Shrubbery("Shrubbery"); // sign 145, exec 137
	RobotomyRequestForm Robotomy("Robotomy"); // sign 72, exec 45
	PresidentialPardonForm Presidental("Presidental"); // sing 25, exec 5
	ShrubberyCreationForm notSigned("Not Signed");

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Execute Form" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	Brendon.signForm(Shrubbery);
	Brendon.signForm(Robotomy);
	Brendon.signForm(Presidental);
	Brendon.executeForm(Shrubbery);
	Brendon.executeForm(Robotomy);
	Brendon.executeForm(Presidental);


	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Failed Form" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;

	Joao.signForm(Shrubbery);
	Joao.executeForm(Shrubbery);
	Joao.signForm(Robotomy);
	Joao.executeForm(Robotomy);
	Joao.signForm(Presidental);
	Joao.executeForm(Presidental);
	Brendon.executeForm(notSigned);

	std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
}