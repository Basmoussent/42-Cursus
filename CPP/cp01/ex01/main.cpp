/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:29:46 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 19:49:52 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "John";

    std::cout << CYAN << "🛠 Création de la horde de " << N << " zombies...\n" << RESET;
    Zombie* list = zombieHorde(N, name);

    std::cout << GREEN << "✅ Zombies créés avec succès !\n" << RESET;
    
    std::cout << YELLOW << "🔁 Affichage de chaque zombie :\n" << RESET;
    for (int i = 0; i < N; i++)
    {
        std::cout << "🧟 " << i + 1 << ": ";
        list[i].announce();
    }

    std::cout << RED << "\n💀 Suppression de la horde...\n" << RESET;
    delete[] list;

    std::cout << GREEN << "🧹 Mémoire libérée proprement !\n" << RESET;
    return 0;
}