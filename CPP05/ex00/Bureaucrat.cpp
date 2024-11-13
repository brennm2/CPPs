/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:04:40 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/13 18:10:25 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


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
	try
	{
		this->_grade = verify_grade(tempGrade);
		std::cout << green <<"Grade decremented!" << reset << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error while trying to decrement-> "<< red << e.what() << '\n' << reset;
	}
	
}


void	Bureaucrat::incrementGrade()
{
	int tempGrade = getGrade();
	tempGrade -= 1;
	try
	{
		this->_grade = verify_grade(tempGrade);
		std::cout << green <<"Grade incremented!" << reset << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error while trying to increment-> "<< red <<e.what() << '\n' << reset;
	}
	
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
	try
	{
		this->_grade = verify_grade(tempGrade);
		std::cout << green << this->getName() << \
		" grade set to: " << blue << this->_grade << "\n" << reset;
		
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error while trying to increment-> " << red << e.what() << '\n' << reset;
	}
	
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
	try
	{
		this->_grade = verify_grade(newgrade);
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
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