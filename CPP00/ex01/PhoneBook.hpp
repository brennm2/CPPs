/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:41:10 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/04 13:37:35 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
#include "Contact.hpp"

class Phonebook
{
private:
	Contact Contacts[8];

public:
	void	set_ContactsIndex();

	void	Set_PhoneBookContacts(std::string FName, std::string LName,
			std::string NName, std::string DSecret, int PNumber, int Index);
	bool	print_columns(int index);
	void	get_ContactInfo(int index);
};

#endif