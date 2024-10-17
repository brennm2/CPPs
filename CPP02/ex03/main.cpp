/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:24:07 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/17 11:23:57 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	Point P1;
	Point P2((4.18f), (3.02f));
	Point P3(P2);
	Point P4((94.16f), (100.12f));
	Point P5((2.56f), (2.08f));
	Point P((1.5f), (1.5f));
	Point P6 = P;
	Point P7((-0.5f), (-0.5f));
	

	Point Tc(0, 0);
	Point Ta(5.12, 4.16);
	Point Tb(1.18, -6.49);

	Point Tx(0, 3.02);
	Point Ty(5, 3.02);
	Point Tz(2.5, 0);

	//One of the vertexes
	std::cout << std::endl;
	std::cout << "P1: one of the vertexes, should be false" << std::endl;
	std::cout << "x: " << P1.getX() << " y: " << P1.getY() << std::endl;
	if (bsp(Ta, Tb, Tc, P1) == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";


	// Inside the triangle
	std::cout << std::endl;
	std::cout << "P2: inside the triangle, should be true" << std::endl;
	std::cout << "x: " << P2.getX() << " y: " << P2.getY() << std::endl;
	if (bsp(Ta, Tb, Tc, P2) == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";
	
	
	//On the edge
	std::cout << std::endl;
	std::cout << "P3: on the edge, should be false" << std::endl;
	std::cout << "x: " << P3.getX() << " y: " << P3.getY() << std::endl;
	if (bsp(Tx, Ty, Tz, P3) == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";

	// Outside the triangle
	std::cout << std::endl;
	std::cout << "P4: outside the triangle, should be false" << std::endl;
	std::cout << "x: " << P4.getX() << " y: " << P4.getY() << std::endl;
	if (bsp(Ta, Tb, Tc, P4) == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";

	// On the edge
	std::cout << std::endl;
	std::cout << "P5: on the edge, should be false" << std::endl;
	std::cout << "x: " << P5.getX() << " y: " << P5.getY() << std::endl;
	if (bsp(Ta, Tb, Tc, P5) == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";


	// Inside
	std::cout << std::endl;
	std::cout << "P6: inside, should be true" << std::endl;
	std::cout << "x: " << P6.getX() << " y: " << P6.getY() << std::endl;
	if (bsp(Tx, Ty, Tz, P6) == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";

	// Outside
	std::cout << std::endl;
	std::cout << "P7: outside the triangle, should be false" << std::endl;
	std::cout << "x: " << P7.getX() << " y: " << P7.getY() << std::endl;
	if (bsp(Tx, Ty, Tz, P7) == true)
		std::cout << "true\n";
	else
		std::cout << "false\n";
	return 0; 
}