/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:14:07 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/04 11:32:44 by bdenfir          ###   ########.fr       */
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
	std::cout << BLACK << "[DEBUG]\n";
	std::cout << BLUE <<"love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << BLACK << "[INFO]\n";
    std::cout << GREEN <<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;

}

void Harl::warning( void )
{
	std::cout << BLACK << "[WARNING]\n";
    std::cout << YELLOW << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << BLACK << "[ERROR]\n";
    std::cout << RED << "This is unacceptable! I want to speak to the manager now." << std::endl;	
}

void Harl::complain(std::string level)
{
    int index = -1;
    
    if (level == "DEBUG") index = 0;
    else if (level == "INFO") index = 1;
    else if (level == "WARNING") index = 2;
    else if (level == "ERROR") index = 3;

    switch (index)
    {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}

