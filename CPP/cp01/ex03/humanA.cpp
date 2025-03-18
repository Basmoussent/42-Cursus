/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:37:00 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 22:03:28 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& wpn) : _wpn(wpn), _name(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack( void )
{
	std::cout << this->_name;
	std::cout << " attacks with their ";
	std::cout << this->_wpn.getType();
	std::cout << std::endl; 
}