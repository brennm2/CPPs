/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:40:59 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/03 11:52:11 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

void	PhoneBook::set_ContactsIndex()
{
	for(int i = 1; i <= 8; i++)
		Contacts[i - 1].set_ContactIndex(i);
}

void	PhoneBook::Set_PhoneBookContacts(std::string FName, std::string LName,
	std::string NName, std::string DSecret, int PNumber, int Index)
{
	Contacts[Index].set_ContactInfo(FName, LName, NName, DSecret, PNumber, Index);
}

void	PhoneBook::print_columns()
{
	int	index;
	std::string Fname;
	std::string Lname;
	std::string Nname;

	std::cout << "\n";
	std::cout << std::right << std::setw(10) << "Index" << "|"
			<< "First Name" << "|"
			<< "Last Name" << "|"
			<< "Nick Name" << "|" << "\n";
	for(int i = 0; i < 8; i++)
	{
		Fname = Contacts[i].get_first_name();
		Lname = Contacts[i].get_last_name();
		Nname = Contacts[i].get_nick_name();
		index = Contacts[i].get_index();

		std::cout << std::right << std::setw(10) << index << "|";
		std::cout << Fname << "|";
		std::cout << Lname << "|";
		std::cout << Nname << "|";
		std::cout << "\n";
	}
	std::cout << "\n";
}

void	PhoneBook::get_ContactInfo()
{
	int	option;

	std::cout << "Which contact do you want to see?\n";
	std::cin >> option;
	if (std::cin.fail() || std::cin.eof() || (option <= 0 || option >= 9))
	{
		std::cout << "\033[31m" <<"\nInvalid Option\n\n" << "\033[0m";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	else
	{
		Contacts[option - 1].print_ContactInfo();
	}
}