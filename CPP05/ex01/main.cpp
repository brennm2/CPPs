/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:34:14 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/13 18:10:56 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Fernando("Fernando", 500);
	Bureaucrat Caio("Caio", 0);
	Bureaucrat Jorge("Jorge", -5);
	Bureaucrat Brendon("Brendon", 2);
	

	//Test with increment
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Test Increment" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	
	std::cout << Brendon;
	Brendon.incrementGrade();
	std::cout << Brendon;

	//Test with decrement
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Test Decrement" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	std::cout << Brendon;
	Brendon.decrementGrade();
	std::cout << Brendon;



	//Error testing
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Test Error" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	Brendon.setGrade(150);
	Brendon.decrementGrade();
	Brendon.setGrade(1);
	Brendon.incrementGrade();
	std::cout << "\n";
	Brendon.setGrade(500);
	Brendon.setGrade(-50);
	Brendon.setGrade(0);

	//Overload testing
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Overload testing" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	std::cout << Brendon;
	

	std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
}