/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:05:21 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/14 13:50:23 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
	Harl HarlComplainer;

	HarlComplainer.complain("DEBUG");
	HarlComplainer.complain("INFO");
	HarlComplainer.complain("WARNING");
	HarlComplainer.complain("ERROR");
	HarlComplainer.complain("NOTHING");


}