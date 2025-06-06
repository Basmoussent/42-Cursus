/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:05:56 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/19 14:18:33 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


class FragTrap: virtual public ClapTrap
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

