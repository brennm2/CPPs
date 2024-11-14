/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:22:14 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/14 17:25:47 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
#define AFORM_HPP

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

class AForm
{
private:
	const std::string 	_name;
	bool				_isSigned;
	const int 			_gradeToSign;
	const int			_gradeToExecute;
	const std::string	_target;
public:

	void		beSigned(Bureaucrat &toSign);
	std::string	getName(void) const;
	std::string	getTarget(void) const;
	bool		getIsSigned(void) const;
	std::string	getIsSignedToString(void) const;
	int			getGradeToSign(void) const;
	int			getGradeToExecute(void) const;



	AForm();
	AForm(std::string newName, int newGradeToSign, int newGradeToExecute, std::string newTarget);
	~AForm();
	AForm(const AForm &copy);
	AForm &operator=(const AForm &copy);

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

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif