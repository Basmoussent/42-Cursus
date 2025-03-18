/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:20:42 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 22:14:38 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <iostream>
#include "string"

class HumanB
{
private:
	Weapon *_wpn;
	std::string _name;
public:
	HumanB(std::string name);
	~HumanB();
	void attack( void );
	void setWeapon (Weapon& wpn);
};
