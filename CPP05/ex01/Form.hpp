/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:22:14 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/14 15:41:46 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"


// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"

class Bureaucrat;

class Form 
{
private:
	const std::string 	_name;
	bool				_isSigned;
	const int 			_gradeToSign;
	const int			_gradeToExecute;
public:

	void		beSigned(Bureaucrat &toSign);
	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	std::string	getIsSignedToString(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;



	Form();
	Form(std::string newName, int newGradeToSign, int newGradeToExecute);
	~Form();
	Form(const Form &copy);
	Form &operator=(const Form &copy);

		class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};

	class GradeIsNegative : public std::exception
	{
		const char* what() const throw();
	};
} ;

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif