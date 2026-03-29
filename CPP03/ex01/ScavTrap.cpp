/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 12:12:10 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 12:12:10 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "[ScavTrap] default constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->isguard = false;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "[ScavTrap] " << name << " constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->isguard = false;
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy)
{
	std::cout << "[ScavTrap] copy constructor called.\n";
	this->isguard = copy.isguard;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& rhs)
{
	if (this == &rhs)
		return (*this);
	ClapTrap::operator=(rhs);
	this->isguard = rhs.isguard;
	std::cout << "[ScavTrap] copy assignment operator called." << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "[ScavTrap] " << name << " destructor called.\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << "[ScavTrap] " << name << " cannot attack (no hit points left)." << std::endl;
	else if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "[ScavTrap] " << name << " attacks " << target << ", causing " << attackDamage << " points of damage. Energy left: " << energyPoints << std::endl;
	}
	else
		std::cout << "[ScavTrap] " << name << " cannot attack (insufficient energy points)." << std::endl;
}

void ScavTrap::guardGate()
{
	if (isguard)
		std::cout << "[ScavTrap] " << name << " is already in Gate keeper mode." << std::endl;
	else
	{
		isguard = true;
		std::cout << "[ScavTrap] " << name << " has entered Gate keeper mode." << std::endl;
	}
}