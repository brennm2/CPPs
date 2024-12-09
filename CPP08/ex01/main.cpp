/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 18:05:48 by bde-souz          #+#    #+#             */
/*   Updated: 2024/12/09 18:35:45 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	try
	{
		Span newSpan(5);

		newSpan.addNumber(1);
		newSpan.addNumber(2);
		newSpan.addNumber(3);
		newSpan.addNumber(4);
		newSpan.addNumber(5);
		newSpan.addNumber(6);
		
		newSpan.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << red << e.what() << '\n' << reset;
	}
	
	
	



}