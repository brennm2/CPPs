/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:47:51 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 13:55:57 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

void	PresidentialPardonForm::executor() const
{
	std::cout << green << this->getTarget() << blue \
		<<" has been pardoned by Zaphod Beeblebrox." << "\n";
}

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Default", 25, 5, "Default")
{
	std::cout << magenta << "PresidentialPardonForm Default Constructor Called\n" << reset;
}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget)
	: AForm("Presidential", 25, 5, newTarget)
{
	std::cout << magenta << "PresidentialPardonForm Target Constructor Called\n" << reset;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << red << "PresidentialPardonForm Destructor Called\n" << reset;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
	: AForm(copy)
{
	std::cout << cyan << "PresidentialPardonForm Copy Constructor Called\n" << reset;
	*this = copy;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << cyan << "PresidentialPardonForm Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}