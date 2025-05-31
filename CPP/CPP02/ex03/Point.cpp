/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:58:12 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/19 12:04:30 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}

Point::Point(const Point &src) : _x(src._x), _y(src._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::~Point(void) {}

Point &Point::operator=(const Point &src)
{
	
	if (this != &src)
	{
		this->_x = src._x;
		this->_y = src._y;
	}
	return *this;
}

const Fixed &Point::getX(void) const
{
	return this->_x;
}

const Fixed &Point::getY(void) const
{
	return this->_y;
}

std::ostream &operator<<(std::ostream &o, Point const point)
{
	o << "Point(" << point.getX() << ", " << point.getY() << ")";
	return o;
}