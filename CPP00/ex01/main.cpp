/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:41:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/02 18:56:50 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"



bool	fail_cin(void)
{
	if (std::cin.fail() || std::cin.eof())
	{
		std::cout << "\nInvalid Option\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (false);
	}
	else
		return (true);
}


bool	option_Add(PhoneBook &Phone_book, int index)
{
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string DarkestSecret;
	int	PhoneNumber;

	std::cout << "Enter First Name: ";
	std::cin >> FirstName;
	if (!fail_cin())
		return (false);
	std::cout << "\n";

	std::cout << "Enter First Last Name: ";
	std::cin >> LastName;
	if (std::cin.fail() || std::cin.eof())
		return (fail_cin());
	std::cout << "\n";

	std::cout << "Enter Nick Name: ";
	std::cin >> NickName;
	if (std::cin.fail() || std::cin.eof())
		return (fail_cin());
	std::cout << "\n";

	std::cout << "Enter Dakerst Secret: ";
	std::cin >> DarkestSecret;
	if (std::cin.fail() || std::cin.eof())
		return (fail_cin());
	std::cout << "\n";

	std::cout << "Enter Phone Number: ";
	std::cin >> PhoneNumber;
	if (std::cin.fail() || std::cin.eof())
		return (fail_cin());
	std::cout << "\n";

	Phone_book.Set_PhoneBookContacts(FirstName, LastName, NickName,
		DarkestSecret, PhoneNumber, index);
	return (true);
}



int main()
{
	PhoneBook Phone_book;
	std::string option;
	int	index = 0;

	Phone_book.set_ContactsIndex();
	while(1)
	{
		if (std::cin.eof())
		{
			std::cout << "\nExiting now\n\n";
			return (0);
		}
		std::cout << "Not so Awesome Phonebook!\n";
		std::cout << "What do you want to do?\n";
		std::cout << "\n ADD | SEARCH | EXIT\n";
		std::cin >> option;

		if (option == "ADD")
		{
			if (index == 1)
				option_Add(Phone_book, 1);
			else if (option_Add(Phone_book, index) == 1)
				index++;
		}
		else if (option == "SEARCH")
			Phone_book.print_columns();
		else if (option == "EXIT" || std::cin.eof())
		{
			std::cout << "Exiting now\n";
			return (0);
		}
		else
		{
			std::cout << "\nInvalid Option\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}