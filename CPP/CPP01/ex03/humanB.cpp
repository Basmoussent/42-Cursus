/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:20:33 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 22:20:02 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_wpn = NULL;
}

HumanB::~HumanB()
{
}

void HumanB::attack()
{
    if (this->_wpn)
    {
        std::cout << this->_name << " attacks with their " << this->_wpn->getType() << std::endl;
    }
    else
    {
        std::cout << this->_name << " has no weapon!" << std::endl;
    }
}

void HumanB::setWeapon (Weapon& wpn)
{
	this->_wpn = &wpn;
}