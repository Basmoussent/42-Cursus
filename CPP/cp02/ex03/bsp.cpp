/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:45:01 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/18 19:33:25 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float crossProduct(Point p1, Point p2, Point p3) {
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) - (p2.getY() - p1.getY()) * (p3.getX() - p1.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float d1 = crossProduct(a, b, point);
    float d2 = crossProduct(b, c, point);
    float d3 = crossProduct(c, a, point);

    bool has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
    bool has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

    return !(has_neg && has_pos);
}
