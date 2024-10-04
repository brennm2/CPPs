/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:40:59 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/04 13:52:38 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	Phonebook::set_ContactsIndex()
{
	for(int i = 1; i <= 8; i++)
		Contacts[i - 1].set_ContactIndex(i);
}

void	Phonebook::Set_PhoneBookContacts(std::string FName, std::string LName,
	std::string NName, std::string DSecret, int PNumber, int Index)
{
	Contacts[Index].set_ContactInfo(FName, LName, NName, DSecret, PNumber, Index);
}

bool	Phonebook::print_columns(int index_out)
{
	int	list_position;
	std::string Fname;
	std::string Lname;
	std::string Nname;

	if (index_out <= 0)
	{
		std::cout << "\033[31m" << "\nEmpty Phonebook!\n\n" << "\033[0m";
		return false;
	}
	else
	{
		std::cout << "\n";
		std::cout << std::right << std::setw(10) << "Index" << "|"
				<< std::right << std::setw(10) << "First Name" << "|"
				<< std::right << std::setw(10) << "Last Name" << "|"
				<< std::right << std::setw(10) << "Nick Name" << "|" << "\n";
		for(int i = 0; i < index_out; i++)
		{
			Fname = Contacts[i].get_first_name();
			Lname = Contacts[i].get_last_name();
			Nname = Contacts[i].get_nick_name();
			list_position = Contacts[i].get_index();
			std::cout << std::right << std::setw(10) << list_position << "|";
			std::cout << std::right << std::setw(10) << Fname << "|";
			std::cout << std::right << std::setw(10) << Lname << "|";
			std::cout << std::right << std::setw(10) << Nname << "|";
			std::cout << "\n";
		}
		std::cout << "\n";
		return (true);
	}
}

void	Phonebook::get_ContactInfo(int index)
{
	int	option;

	std::cout << "What do you want to do?\n";
	std::cout << "Return with 0 or select a number\n";
	std::cin >> option;
	if (std::cin.fail() || std::cin.eof() || (option < 0 || option >= 9))
	{
		std::cout << "\033[31m" <<"\nInvalid Option\n\n" << "\033[0m";
	}
	else if (option > index)
	{
		std::cout << "\033[31m" <<"\nInvalid Option(Contact Empty!)\n\n" << "\033[0m";
	}
	else if (option == 0)
		std::cout << "\033[32m" << "\nGoing back!\n\n" << "\033[0m";
	else
	{
		Contacts[option - 1].print_ContactInfo();
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}