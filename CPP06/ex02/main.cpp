/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:47:31 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/27 13:40:41 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base	*generate(void)
{
	std::srand((unsigned) time(NULL));
	int random = std::rand() % 3;

	switch (random)
	{
	case (0):
		return (new A);
		break;
	case (1):
		return (new B);
		break;
	case (2):
		return (new C);
		break;
	}
	return (NULL);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << green << "The type of the Object is: " \
			<< blue << "A" << green << "!" << reset << "\n";
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << green << "The type of the Object is: " \
			<< blue << "B" << green << "!" << reset << "\n";
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << green << "The type of the Object is: " \
			<< blue << "C" << green << "!" << reset << "\n";
	}
	else
		std::cout << red << "Problem with the type of the Object!" \
			<< reset << "\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << green << "The type of the Object is: " \
			<< blue << "A" << green << "!" << reset << "\n";
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << green << "The type of the Object is: " \
				<< blue << "B" << green << "!" << reset << "\n";
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << green << "The type of the Object is: " \
					<< blue << "C" << green << "!" << reset << "\n";
			}
			catch(const std::exception& e)
			{
				std::cout << red << "Problem with the type of the Object!" \
					<< reset << "\n";
			}
		}
	}
}



int main(void)
{
	Base *newBase;

	newBase = generate();
	if (newBase == NULL)
		return (0);
	
	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Identify with Pointer" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	identify(newBase);
	std::cout << "\n";

	std::cout << yellow << "\n⫘⫘⫘⫘⫘⫘  " << "Identify with Reference" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	identify(*newBase);

	std::cout << magenta << "\n\n⫘⫘⫘⫘⫘⫘  " << "DESTRUCTOR SEPARATOR" << "  ⫘⫘⫘⫘⫘⫘" << "\n" << reset;
	delete newBase;
}