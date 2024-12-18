/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:26:17 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/14 16:46:21 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"



void	Form::beSigned(Bureaucrat &toSign)
{
	std::cout << cyan << "Using: " << green << toSign.getName() \
		<< cyan << " to sign the " << green << this->getName() << "\n" << reset;
	if (this->_gradeToSign < toSign.getGrade())
	{
		throw (GradeTooLowException());
	}
	else
	{
		std::cout << green << toSign.getName() << cyan <<" signed: " \
			<< green << this->getName() << "\n" << reset;
		this->_isSigned = true;
	}
	
} 

int	Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

int	Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

std::string Form::getIsSignedToString() const
{
	if (this->getIsSigned() == false)
		return ("False");
	else
		return ("True");
}

bool	Form::getIsSigned() const
{
	
	return (this->_isSigned);
}

std::string Form::getName() const
{
	return (this->_name);
}


Form::Form()
	: _name("default"), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << magenta << "Form Default Constructor Called\n" << reset;
	this->_isSigned = false;
}

Form::Form(std::string newName, int newGradeToSign, int newGradeToExecute)
	: _name(newName), _gradeToSign(newGradeToSign), _gradeToExecute(newGradeToExecute)
{
	std::cout << magenta << "Form Name Constructor Called\n" << reset;
	if (newGradeToExecute == 0 || newGradeToSign == 0)
		throw GradeTooHighException();
	else if (newGradeToExecute > 150 || newGradeToSign > 150)
		throw GradeTooLowException();
	else if (newGradeToExecute < 0 || newGradeToSign < 0)
		throw GradeIsNegative();
	else
		this->_isSigned = false;
}

Form::~Form()
{
	std::cout << red << "Form Destructor Called\n" << reset;
}

Form::Form(const Form &copy)
	: _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	std::cout << cyan << "Form Copy Constructor Called\n" << reset;
	this->_isSigned = copy._isSigned;
}

Form &Form::operator=(const Form &copy)
{
	std::cout << cyan << "Form Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << blue << form.getName() << green << " form is signed?: " << blue << form.getIsSignedToString() << "\n" << reset \
	<< green << "Grade to Sign: " << blue << form.getGradeToSign() << reset << "\n" \
	<< green << "Grade to execute: " << blue << form.getGradeToExecute() << reset << "\n";
	return out;
}


const char* Form::GradeTooHighException::what() const throw()
{
	return "Error: Grade too High!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Error: Grade too Low!";
}

const char* Form::GradeIsNegative::what() const throw()
{
	return "Error: New Grade is negative!";
}