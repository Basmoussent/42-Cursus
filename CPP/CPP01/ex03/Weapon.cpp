/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:26:25 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 21:56:39 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type )
{
	this->_type = type;
}

Weapon::Weapon( void )
{
	
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

std::string Weapon::getType( void )
{
	return this->_type;
}