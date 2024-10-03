/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:41:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/03 17:16:44 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

bool	fail_cin(void)
{
	if (std::cin.fail() || std::cin.eof())
	{
		std::cout << "\033[31m" <<"\nInvalid Option\n\n" << "\033[0m";
		// std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
	std::getline(std::cin, FirstName);
	if (FirstName.empty())
	{
		std::cout << "\033[31m" <<"\nInvalid Option (Empty line)\n\n" << "\033[0m";
		return false;
	}
	std::cout << "\n";

	std::cout << "Enter Last Name: ";
	std::getline(std::cin, LastName);
	if (LastName.empty())
	{
		std::cout << "\033[31m" <<"\nInvalid Option (Empty line)\n\n" << "\033[0m";
		return false;
	}
	std::cout << "\n";

	std::cout << "Enter Nick Name: ";
	std::getline(std::cin, NickName);
	if (NickName.empty())
	{
		std::cout << "\033[31m" <<"\nInvalid Option (Empty line)\n\n" << "\033[0m";
		return false;
	}
	std::cout << "\n";

	std::cout << "Enter Dakerst Secret: ";
	std::getline(std::cin, DarkestSecret);
	if (DarkestSecret.empty())
	{
		std::cout << "\033[31m" <<"\nInvalid Option (Empty line)\n\n" << "\033[0m";
		return false;
	}
	std::cout << "\n";

	std::cout << "Enter Phone Number: ";
	std::cin >> PhoneNumber;
	if (std::cin.fail() || std::cin.eof())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "\033[31m" <<"\nInvalid Option\n\n" << "\033[0m";
		return false;
	}
	std::cout << "\n";

	Phone_book.Set_PhoneBookContacts(FirstName, LastName, NickName,
		DarkestSecret, PhoneNumber, index);
	std::cout << "\033[32m" << "Contact added!\n\n" << "\033[0m";
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (true);
}

int main()
{
	PhoneBook Phone_Book;
	std::string option;
	int	index = 0;

	Phone_Book.set_ContactsIndex();
	while(1)
	{
		if (std::cin.eof())
		{
			std::cout << "Exiting now\n";
			break;
		}
		std::cout << "\033[1;34m" << "Not so Awesome Phonebook!\n" << "\033[0m";
		std::cout << "What do you want to do?\n";
		std::cout << "\n ADD | SEARCH | EXIT\n";
		std::getline(std::cin, option);


		if (option == "ADD")
		{
			if (index == 7)
				option_Add(Phone_Book, 7);
			else if (option_Add(Phone_Book, index) == true)
				index++;
		}
		else if (option == "SEARCH")
		{
			if (Phone_Book.print_columns(index) == true)
				Phone_Book.get_ContactInfo();
		}
		else if (option == "EXIT" || std::cin.eof())
		{
			std::cout << "Exiting now\n";
			return (0);
		}
		else
		{
			std::cout << "\033[31m" <<"\nInvalid Option\n\n" << "\033[0m";
			std::cin.clear();
		}
	}
}