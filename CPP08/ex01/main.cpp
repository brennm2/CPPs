/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:05:48 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/12 11:35:58 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Test positive Span" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Span newSpan(5);

		newSpan.addNumber(5);
		newSpan.addNumber(4);
		newSpan.addNumber(7);
		newSpan.addNumber(10);
		newSpan.addNumber(57);
		
		std::cout << cyan <<"Shortest Span: " \
			<< green << newSpan.shortestSpan() << "\n" << reset;

		std::cout << cyan <<"Longest Span: " \
			<< green << newSpan.longestSpan() << "\n" << reset;

		newSpan.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Test negative Span" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Span newSpan(5);

		newSpan.addNumber(-5);
		newSpan.addNumber(-14);
		newSpan.addNumber(-55);
		newSpan.addNumber(-80);
		newSpan.addNumber(-100);
		
		std::cout << cyan <<"Shortest Span: " \
			<< green << newSpan.shortestSpan() << "\n" << reset;

		std::cout << cyan <<"Longest Span: " \
			<< green << newSpan.longestSpan() << "\n" << reset;

		newSpan.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "No space test" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Span newSpan(5);

		newSpan.addNumber(1);
		newSpan.addNumber(2);
		newSpan.addNumber(3);
		newSpan.addNumber(4);
		newSpan.addNumber(5);
		newSpan.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Add amount" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	try
	{
		Span newSpan(5);

		newSpan.addRNumber(5);

		std::cout << cyan <<"Shortest Span: " \
			<< green << newSpan.shortestSpan() << "\n" << reset;

		std::cout << cyan <<"Longest Span: " \
			<< green << newSpan.longestSpan() << "\n" << reset;


		newSpan.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	



}