/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:26:09 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/02 18:40:10 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_ContactInfo(std::string FName, std::string LName, std::string NName, std::string DSecret, int PNumber, int i)
{
	FirstName = FName;
	LastName = LName;
	NickName = NName;
	DarkestSecret = DSecret;
	PhoneNumber = PNumber;
	Index = i + 1;
}

void Contact::set_ContactIndex(int i)
{
	Index = i;
}

std::string Contact::get_first_name()
{
	if (FirstName.length() > 10)
		return FirstName.substr(0, 9) + '.';
	else
		return (FirstName);
}

std::string Contact::get_last_name()
{
	if (LastName.length() > 10)
		return LastName.substr(0, 9) + '.';
	else
		return (LastName);
}

std::string Contact::get_nick_name()
{
	if (NickName.length() > 10)
		return NickName.substr(0, 9) + '.';
	else
		return (NickName);
}

int Contact::get_index()
{
	return (Index);
}