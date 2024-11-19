/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:26:17 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 23:36:23 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void	AForm::execute(Bureaucrat const & bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getGradeToExecute())
		throw(GradeTooLowException());
	else
	{
		if (this->getIsSigned() == true)
			this->executor();
		else
		{
			std::cout << green << this->getName() << \
				red << "is not signed!" << reset << "\n";
		}
	}
}

void	AForm::beSigned(Bureaucrat &toSign)
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

int	AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

int	AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

std::string AForm::getIsSignedToString() const
{
	if (this->getIsSigned() == false)
		return ("False");
	else
		return ("True");
}

bool	AForm::getIsSigned() const
{
	
	return (this->_isSigned);
}

std::string AForm::getName() const
{
	return (this->_name);
}

std::string AForm::getTarget() const
{
	return (this->_target);
}


AForm::AForm()
	: _name("default"), _gradeToSign(150), _gradeToExecute(150), _target("default")
{
	std::cout << magenta << "AForm Default Constructor Called\n" << reset;
	this->_isSigned = false;
}

AForm::AForm(std::string newName, int newGradeToSign, int newGradeToExecute, std::string newTarget)
	: _name(newName), _gradeToSign(newGradeToSign), \
	_gradeToExecute(newGradeToExecute), _target(newTarget)
{
	std::cout << magenta << "AForm Name Constructor Called\n" << reset;
	if (newGradeToExecute == 0 || newGradeToSign == 0)
		throw GradeTooHighException();
	else if (newGradeToExecute > 150 || newGradeToSign > 150)
		throw GradeTooLowException();
	else if (newGradeToExecute < 0 || newGradeToSign < 0)
		throw GradeIsNegative();
	else
		this->_isSigned = false;
}

AForm::~AForm()
{
	std::cout << red << "AForm Destructor Called\n" << reset;
}

AForm::AForm(const AForm &copy)
	: _name(copy._name), _gradeToSign(copy._gradeToSign), \
	_gradeToExecute(copy._gradeToExecute), _target(copy._target)
{
	std::cout << cyan << "AForm Copy Constructor Called\n" << reset;
	this->_isSigned = copy._isSigned;
}

AForm &AForm::operator=(const AForm &copy)
{
	std::cout << cyan << "AForm Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_isSigned = copy._isSigned;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << blue << form.getName() << green << " form is signed?: " << blue << form.getIsSignedToString() << "\n" << reset \
	<< green << "Grade to Sign: " << blue << form.getGradeToSign() << reset << "\n" \
	<< green << "Grade to execute: " << blue << form.getGradeToExecute() 
	<< green "Target is: " << blue << form.getTarget() << reset << "\n";
	return out;
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error: Grade too High!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error: Grade too Low!";
}

const char* AForm::GradeIsNegative::what() const throw()
{
	return "Error: New Grade is negative!";
}
