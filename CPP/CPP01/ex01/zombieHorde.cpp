/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:25:07 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/04 10:58:54 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N < 1)
	{	
		std::cout <<  RED <<"Invalid number of zombies, Try again !" << std::endl;
		return NULL;
	}
	Zombie* list = new Zombie[N];
	
	for (int i = 0; i < N; i++)
	{
		list[i].setname(name);
	}
	return (list);
}