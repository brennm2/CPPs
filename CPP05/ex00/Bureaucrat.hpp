/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:04:43 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/14 13:14:05 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <string>
#include <stdexcept>

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


class Bureaucrat
{
private:

	const std::string _name;
	int				_grade;
public:

	int						verify_grade(int newgrade);
	const std::string		getName() const;
	int						getGrade() const;
	void					incrementGrade();
	void					decrementGrade();
	void					setGrade(int newGrade);


	Bureaucrat();
	Bureaucrat(std::string newname, int newgrade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);


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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif