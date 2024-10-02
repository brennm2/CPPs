/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 18:23:44 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/02 18:56:36 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <limits>

class Contact
{
private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string DarkestSecret;
	int	PhoneNumber;
	int	Index;

public:

	void		set_ContactInfo(std::string FName, std::string LName, \
		std::string NName, std::string DSecret, int PNumber, int i);
	void		set_ContactIndex(int i);
	std::string get_first_name();
	std::string get_last_name();
	std::string get_nick_name();
	int			get_index();
	Contact()
	{
		FirstName = "Empty";
		LastName = "Empty";
		NickName = "Empty";
		DarkestSecret = "Empty";
		PhoneNumber = 0;
		Index = 0;
	}
};

#endif