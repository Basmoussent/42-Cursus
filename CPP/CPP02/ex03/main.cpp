/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:58:43 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/19 12:08:25 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void )
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(2, 2);
	Point outside(20, 20);
	Point edge(0, 5);

	std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
	std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;
	std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;

	return (0);
}