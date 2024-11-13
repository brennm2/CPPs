/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:26:17 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/13 18:49:02 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
	: _name ("default"), _gradeToExecute
{
	std::cout << magenta << "Form Default Constructor Called\n" << reset;
	this-> = "default";
}

Form::~Form()
{
	std::cout << red << "Form Destructor Called\n" << reset;
}

Form::Form(const Form &copy)
{
	std::cout << cyan << "Form Copy Constructor Called\n" << reset;
	this->HERE = copy.HERE;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << cyan << "Form Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->HERE = copy.HERE;
	}
	return (*this);
}