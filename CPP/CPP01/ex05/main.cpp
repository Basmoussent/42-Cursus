/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 23:22:28 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/04 11:17:26 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl karen = Harl();
	std::cout << BLACK << "[DEBUG] : ";
	karen.complain("DEBUG");
	std::cout << BLACK << "[INFO] : ";
	karen.complain("INFO");
	std::cout << BLACK << "[WARNING] : ";
	karen.complain("WARNING");
	std::cout << BLACK << "[ERROR] : ";
	karen.complain("ERROR");
	std::cout << BLACK << "[?????] : ";
	karen.complain("test");
}