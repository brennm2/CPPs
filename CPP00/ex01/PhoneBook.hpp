/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:41:10 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/03 11:52:36 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact Contacts[8];

public:

	void	set_ContactsIndex();

	void	Set_PhoneBookContacts(std::string FName, std::string LName,
		std::string NName, std::string DSecret, int PNumber, int Index);

	void	print_columns();
	void	get_ContactInfo();
};

#endif