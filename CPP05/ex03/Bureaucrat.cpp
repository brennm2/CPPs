/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:04:40 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 23:49:37 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	Bureaucrat::executeForm(AForm const &toExecute)
{
	if (toExecute.getIsSigned() == true)
	{
		if (this->getGrade() <= toExecute.getGradeToExecute())
		{
			std::cout << green << this->getName() << " executed " \
				<< red << toExecute.getName() << "\n" << reset;
			toExecute.execute(*this);
		}
		else
		{
			std::cout << green << this->getName() << red \
				<< " don't have the grade to execute!" << "\n" << reset;
		}
	}
	else
	{
		std::cout << green << toExecute.getName() << red \
			<< " is not signed!" << "\n" << reset;
	}
}

void	Bureaucrat::signForm(AForm &toSign)
{
	try
	{
		toSign.beSigned(*this);
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << green << this->getName() << cyan << " couldn't sign " \
		<< green << toSign.getName() \
		<< cyan <<" because grade is too low!\n" << reset;
	}
}

int	Bureaucrat::verify_grade(int newgrade)
{
	if (newgrade == 0)
		throw Bureaucrat::GradeTooHighException();
	else if (newgrade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (newgrade < 0)
		throw Bureaucrat::GradeIsNegative();
	else
		return (newgrade);
}

void	Bureaucrat::decrementGrade()
{
	int tempGrade = getGrade();
	tempGrade += 1;

	//Output text
	std::cout << cyan << "Trying to decrement grade: " << green << getGrade() \
	<< cyan << ", to: " << green << tempGrade << "\n" << reset;

	this->_grade = verify_grade(tempGrade);

	//Output text
	std::cout << green <<"Grade decremented!" << reset << "\n";
}


void	Bureaucrat::incrementGrade()
{
	int tempGrade = getGrade();
	tempGrade -= 1;

	//Output text
	std::cout << cyan << "Trying to increment grade: " << green << getGrade() \
	<< cyan << ", to: " << green << tempGrade << "\n" << reset;

	this->_grade = verify_grade(tempGrade);
	
	//Output text
	std::cout << green <<"Grade incremented!" << reset << "\n";
}


const std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int newGrade)
{
	int tempGrade = newGrade;
	this->_grade = verify_grade(tempGrade);
	std::cout << green << this->getName() << \
	" grade set to: " << blue << this->_grade << "\n" << reset;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << green << bureaucrat.getName() + ", bureaucrat grade: " \
		<< blue << bureaucrat.getGrade() << "\n" << reset;
	return out;
}


Bureaucrat::Bureaucrat()
	: _name ("default")
{
	std::cout << magenta << "Bureaucrat Default Constructor Called\n" << reset;
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string newname, int newgrade)
	: _name(newname)
{
	std::cout << magenta << "Bureaucrat Grade Constructor Called\n" << reset;
	this->_grade = verify_grade(newgrade);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << red << "Bureaucrat Destructor Called\n" << reset;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	std::cout << cyan << "Bureaucrat Copy Constructor Called\n" << reset;
	this->_grade = copy._grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << cyan << "Bureaucrat Copy Assignment Operator Called\n" << reset;
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Error: Grade too High!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Error: Grade too Low!";
}

const char* Bureaucrat::GradeIsNegative::what() const throw()
{
	return "Error: New Grade is negative!";
}