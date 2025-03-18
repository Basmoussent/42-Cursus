/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:13:45 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 19:18:30 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << CYAN << "\n🧟 Welcome to the Zombie Apocalypse! 🧟\n" << RESET;

    std::cout << YELLOW << "\n[1] Creating a new Zombie dynamically..." << RESET << std::endl;
    Zombie* z1 = newZombie("Walker");
    usleep(500000);
    z1->announce();

    std::cout << GREEN << "\n[2] Summoning a random Zombie..." << RESET << std::endl;
    usleep(500000);
    randomChump("Runner");

    std::cout << RED << "\n[3] Deleting the dynamically created Zombie..." << RESET << std::endl;
    delete z1;

    std::cout << CYAN << "\n✅ All tests completed! Stay safe from the zombies! ✅\n" << RESET;
    return 0;
}
