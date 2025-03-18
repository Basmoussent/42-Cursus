/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:20:47 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 21:55:19 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "string"
#include <iostream>

class Weapon
{
private:
	std::string _type;
public:
	Weapon( std::string type );
	Weapon( void );
	~Weapon();
	
	std::string getType( void );
	void setType( std::string type );
};
