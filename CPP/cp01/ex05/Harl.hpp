/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:11:34 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 23:31:37 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define PURPLE  "\e[0;35m"
#define BLACK   "\e[0;37m"

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );
public:
	Harl();
	~Harl();
	void complain( std::string level );
};


