/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:05:56 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/18 22:20:14 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


class FragTrap: public ClapTrap
{
	private:

	public:
		FragTrap();
		FragTrap(const FragTrap &copy);
		FragTrap(std::string name);

		virtual ~FragTrap();

		FragTrap &operator=(const FragTrap &src);

		void highFiveGuys(void);

};

