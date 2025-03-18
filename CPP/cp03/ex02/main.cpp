/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:45:54 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/18 21:15:16 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap claptrap1;
	ClapTrap claptrap2;

	claptrap1.attack("ONE");
	claptrap2.takeDamage(10);
	claptrap2.beRepaired(5);
	return 0;
}