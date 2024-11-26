/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:47:31 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/26 18:20:12 by bde-souz         ###   ########.fr       */
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

	std::cout << "Random nuber: " << random << "\n";
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

void	identifyPtr(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << green << "The type of the Object is: " \
			<< blue << "A" << green << "!" << reset << "\n";
	}
	else if (dynamic_cast<B*>(p) != NULL )
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

void identifyReference(Base& p)
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
	
	identifyPtr(newBase);
	identifyReference(*newBase);
	delete newBase;
}