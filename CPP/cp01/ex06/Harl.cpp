/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:14:07 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/26 12:37:15 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream> 

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}

void Harl::debug( void )
{
	std::cout << BLUE <<"love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << GREEN <<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << RED << "This is unacceptable! I want to speak to the manager now." << std::endl;	
}

void Harl::complain( int level )
{
	switch (level)
	{
	case 0:
		this->debug();
		this->error();
		this->info();
		this->warning();
	case 1:
		this->error();
		this->info();
		this->warning();
	case 2:
		this->info();
		this->warning();
	case 3:
		this->warning();

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
