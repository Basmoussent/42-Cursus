/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:17:11 by bdenfir           #+#    #+#             */
/*   Updated: 2025/02/25 19:37:43 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include "string"
# include <iostream>
# include <cstdlib> 
# include <unistd.h>

# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define CYAN    "\033[1;36m"

class Zombie
{
private:
    std::string _name;
public:
    Zombie( void );
    Zombie(std::string name);
    ~Zombie();
    void announce( void );
    void setname(std::string name);
};

Zombie* newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name);

#endif