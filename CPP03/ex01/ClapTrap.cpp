/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:33:14 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 10:33:14 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "[ClapTrap] " << name << " constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "[ClapTrap] copy constructor called.\n";
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs)
{
	if (this == &rhs)
		return *this;
	this->name = rhs.name;
	this->hitPoints = rhs.hitPoints;
	this->energyPoints = rhs.energyPoints;
	this->attackDamage = rhs.attackDamage;
	std::cout << "[ClapTrap] copy assignment operator called." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] " << name << " destructor called.\n";
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints > 0 &&  hitPoints > 0)
	{
		std::cout << "[ClapTrap] " << name << " attacks " << target << ", causing " << attackDamage << " points of damage." << std::endl;
		energyPoints--;
	}
	else
	{
		std::cout << "[ClapTrap] " << name << " cannot attack (insufficient energy or hit points)." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "[ClapTrap] " << name << " is already destroyed." << std::endl;
		return;
	}
	if (amount >= hitPoints)
		hitPoints = 0;
	else
		hitPoints -= amount;
	std::cout << "[ClapTrap] " << name << " takes " << amount << " damage. Remaining hit points: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints == 0 || hitPoints == 0)
	{
		std::cout << "[ClapTrap] " << name << " cannot repair (insufficient energy or hit points)." << std::endl;
		return;
	}
	hitPoints += amount;
	energyPoints--;
	std::cout << "[ClapTrap] " << name << " repairs for " << amount << " hit points. Current hit points: " << hitPoints << ", energy left: " << energyPoints << std::endl;

}