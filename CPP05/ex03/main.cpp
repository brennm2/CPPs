/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:34:14 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 18:11:15 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{
	// Bureaucrat Brendon("Brendon", 1);
	// Bureaucrat Joao("Joao", 150);
	// ShrubberyCreationForm Shrubbery("Shrubbery"); // sign 145, exec 137
	// RobotomyRequestForm Robotomy("Robotomy"); // sign 72, exec 45
	// PresidentialPardonForm Presidental("Presidental"); // sing 25, exec 5
	// ShrubberyCreationForm notSigned("Not Signed");

	// std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Execute Form" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	// Brendon.signForm(Shrubbery);
	// Brendon.signForm(Robotomy);
	// Brendon.signForm(Presidental);
	// Brendon.executeForm(Shrubbery);
	// Brendon.executeForm(Robotomy);
	// Brendon.executeForm(Presidental);


	// std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Failed Form" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;

	// Joao.signForm(Shrubbery);
	// Joao.executeForm(Shrubbery);
	// Joao.signForm(Robotomy);
	// Joao.executeForm(Robotomy);
	// Joao.signForm(Presidental);
	// Joao.executeForm(Presidental);
	// Brendon.executeForm(notSigned);

	// std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;

	{
		Intern newIntern;
		AForm *form;
		Bureaucrat Brendon ("Brendon", 1);

		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Form Shrubbery Creator" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		form = newIntern.makeForm("shrubbery request", "home");
		Brendon.signForm(*form);
		Brendon.executeForm(*form);

		std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		delete form;
	}

	{
		Intern newIntern;
		AForm *form;
		Bureaucrat Brendon ("Brendon", 1);

		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Form Robotomy Creator" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		form = newIntern.makeForm("robotomy request", "school");
		Brendon.signForm(*form);
		Brendon.executeForm(*form);

		std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		delete form;
	}

	{
		Intern newIntern;
		AForm *form;
		Bureaucrat Brendon ("Brendon", 1);

		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Form Robotomy Creator" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		form = newIntern.makeForm("presidential request", "work");
		Brendon.signForm(*form);
		Brendon.executeForm(*form);

		std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		delete form;
	}

	{
		Intern newIntern;
		AForm *form;
		Bureaucrat Brendon ("Brendon", 1);

		std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Form Invalid Creator" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		form = newIntern.makeForm("no", "yeah");
		if (form == NULL)
			return (0);
		Brendon.signForm(*form);
		Brendon.executeForm(*form);

		std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
		delete form;
	}

}