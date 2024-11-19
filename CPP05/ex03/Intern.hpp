/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 14:17:31 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/19 17:44:55 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_HPP
#define Intern_HPP


#include <iostream>
#include <string>
#include "AForm.hpp"


// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


class Intern
{
private:
	
public:
	AForm *makeForm(std::string formName, std::string target);
	AForm *makeShrubbery(std::string target);
	AForm *makeRobotomy(std::string target);
	AForm *makePresidential(std::string target);

	Intern();
	~Intern();
	Intern(const Intern &copy);
	Intern &operator=(const Intern &copy);
} ;

#endif