/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:57:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/16 16:55:23 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

// P = A + w1(B - A) + w2(C - A)

Fixed getw1(Point a, Point b, Point c, Point p)
{
	Fixed aX = a.getX();
	Fixed aY = a.getY();
	Fixed bX = b.getX();
	Fixed bY = b.getY();
	Fixed cX = c.getX();
	Fixed cY = c.getY();
	Fixed pX = p.getX();
	Fixed pY = p.getY();


	Fixed up;
	Fixed down;
	Fixed w1;


	up = (aX * (cY - aY)) + ((pY - aY) * (cX - aX)) - pX * (cY - aY);
	down = ((bY - aY) * (cX - aX)) - ((bX - aX) * (cY - aY));
	//w1 = aX * (cY - aY) + (pY - aY) * (cX - aX) - pX * (cY - aY) / (bY - aY) * () ;
	
	w1 = up / down;
	
	return (w1);

}

Fixed getw2(Point a, Point b, Point c, Point p, Fixed w1)
{
	Fixed aY = a.getY();
	Fixed bY = b.getY();
	Fixed cY = c.getY();
	Fixed pY = p.getY();

	Fixed w2;

	w2 = (pY - aY - w1 * (bY - aY)) / (cY - aY);


	return (w2);
}

// bool in_on_vertexes(Point const a, Point const b, Point const c, Point const point){
// 	Fixed aX = a.getX();
// 	Fixed aY = a.getY();
// 	Fixed bX = b.getX();
// 	Fixed bY = b.getY();
// 	Fixed cX = c.getX();
// 	Fixed cY = c.getY();
// 	Fixed pX = point.getX();
// 	Fixed pY = point.getY();
	
// 	if ((pX == aX && pY == aY) || (pX == bX && pY == bY) || (pX == cX && pY == cY))
// 	{
// 		std::cout << "The Point is on one of the vertices\n";
// 		return true;
// 	}
// 	else
// 		return false;
// }

// bool is_on_edge(Point const a, Point const b, Point const point)
// {
// Fixed aX = a.getX();
// Fixed aY = a.getY();
// Fixed bX = b.getX();
// Fixed bY = b.getY();
// Fixed pX = point.getX();
// Fixed pY = point.getY();

// Fixed area = (aX * (bY - pY) + bX * (pY - aY) + pX * (aY - bY)) / 2;

// if (area == 0)
// 	return (true);
// else 
// 	return (false);
// }

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1 = getw1(a, b, c, point);
	Fixed w2 = getw2(a, b, c, point, w1);

	// if (in_on_vertexes(a, b, c, point))
	// 	return (false);
	// if (is_on_edge(a, b, point) || is_on_edge(b, c, point) || is_on_edge(c, a, point))
	// 	return (false);
	if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
		return (true);
	else
		return (false);
}