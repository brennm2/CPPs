/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:26:51 by bde-souz          #+#    #+#             */
/*   Updated: 2024/11/27 13:33:52 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serialize_HPP
#define Serialize_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

// COLORS //
#define blue "\033[34m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
#define magenta "\033[35m"
#define cyan "\033[36m"
#define reset "\033[0m"


class Serialize
{
private:
	static		uintptr_t serialize(Data* ptr);
	static		Data* deserialize(uintptr_t raw);
	static void	displayData(Data *ptr);



	Serialize();
	~Serialize();
	Serialize(const Serialize &copy);
	Serialize &operator=(const Serialize &copy);
public:
	void static	converter(Data *option);
	
} ;

#endif