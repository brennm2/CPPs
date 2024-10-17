/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:57:30 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/17 11:40:00 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"


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

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed w1 = getw1(a, b, c, point);
	Fixed w2 = getw2(a, b, c, point, w1);

	if (w1 > 0 && w2 > 0 && (w1 + w2) < 1)
		return (true);
	else
		return (false);
}