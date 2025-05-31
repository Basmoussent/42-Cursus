/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:20:36 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 22:02:10 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"
#include <iostream>

class HumanA
{
private:
	Weapon &_wpn;
	std::string _name;
public:
	HumanA(std::string name, Weapon& wpn);
	~HumanA();
	void attack( void );
};


