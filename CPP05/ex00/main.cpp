/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:34:14 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/14 13:13:19 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Too Low" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Bureaucrat Fernando("Fernando", 500);
		//Trying to use Fernando values
		std::cout << Fernando.getGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Too High" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Bureaucrat Caio("Caio", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Negative" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Bureaucrat Jorge("Jorge", -5);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Increment Grade" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Bureaucrat Brendon("Brendon", 2);
		std::cout << Brendon;
		Brendon.incrementGrade();
		std::cout << Brendon;
		Brendon.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Decrement Grade" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Bureaucrat Brendon("Brendon", 149);
		std::cout << Brendon;
		Brendon.decrementGrade();
		std::cout << Brendon;
		Brendon.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	

	Bureaucrat Brendon("Brendon",1);
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Overload testing" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	std::cout << Brendon;
}