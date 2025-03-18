/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:56:05 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/18 14:58:00 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& copy);

		~Point();

		Point &operator=(const Point &src);

		const Fixed &getX(void)const;
		const Fixed &getY(void)const;

};

std::ostream	&operator<<(std::ostream &o, Point const point);
