/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:59:34 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/29 17:34:13 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


class Brain
{
protected:
	std::string _ideas[100];
public:
	void	createIdeas(void);
	void	speakIdeas(std::string type, unsigned int number);
	void	placeIdeias(unsigned int index, std::string idea);

	Brain();
	~Brain();
	Brain(const Brain &copy);
	Brain &operator=(const Brain &copy);
} ;

#endif