/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:27:01 by bdenfir           #+#    #+#             */
/*   Updated: 2025/03/19 09:38:11 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap"), _guarding_gate(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guarding_gate(false)
{
	std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy), _guarding_gate(false)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	std::cout << "ScavTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	this->_guarding_gate = src._guarding_gate;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	
	if (this->_energyPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	if (this->_hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints -= 1;
}

void ScavTrap::guardGate(void)
{
	if (this->_guarding_gate)
	{
		std::cout << "ScavTrap " << this->_name << " is already guarding the gate!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " has entered in gate keeper mode!" << std::endl;
	this->_guarding_gate = true;
}
