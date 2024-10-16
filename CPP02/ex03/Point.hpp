/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-souz <bde-souz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:18:28 by bde-souz          #+#    #+#             */
/*   Updated: 2024/10/16 14:01:17 by bde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	Fixed _x;
	Fixed _y;

public:
	Fixed getX(void) const;
	Fixed getY(void) const;
	Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	Point &operator=(const Point &copy);
	~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
