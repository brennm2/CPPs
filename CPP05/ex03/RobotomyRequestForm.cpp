/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:14:13 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 13:42:39 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

void	RobotomyRequestForm::executor() const
{
	//random number gettter
	std::srand((unsigned) time(NULL));
	int random = std::rand() % 2;

	std::cout << yellow << "\n*VRRRRRMMMM*" << "\n";
	if (random == 1)
		std::cout << green << this->getTarget() << blue << " has been robotomized successfully!" \
		<< "\n" << reset;
	else
	{
		std::cout << green << this->getTarget() << red << " robotomization failed!" \
		<< "\n" << reset;
	}


}

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Default", 72, 45, "Default")
{
	std::cout << magenta << "RobotomyRequestForm Default Constructor Called\n" << reset;
}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget)
	: AForm("Robotomy", 72, 45, newTarget)
{
	std::cout << magenta << "RobotomyRequestForm Target Constructor Called\n" << reset;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << red << "RobotomyRequestForm Destructor Called\n" << reset;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
	: AForm(copy)
{
	std::cout << cyan << "RobotomyRequestForm Copy Constructor Called\n" << reset;
	*this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << cyan << "RobotomyRequestForm Copy Assignment Operator Called\n" << reset;
	(void)copy;
	return (*this);
}