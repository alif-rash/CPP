/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:45:38 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 18:45:38 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "[FragTrap] default constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "[FragTrap] " << name << " constructor called." << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& copy) : ClapTrap(copy)
{
	std::cout << "[FragTrap] copy constructor called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& rhs)
{
	std::cout << "[FragTrap] copy assignment operator called." << std::endl;
	if (this == &rhs)
		return (*this);
	ClapTrap::operator=(rhs);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "[FragTrap] " << name << " destructor called." << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
		std::cout << "[FragTrap] " << name << " cannot attack (no hit points left)." << std::endl;
	else if (energyPoints > 0)
	{
		energyPoints--;
		std::cout << "[FragTrap] " << name << " attacks " << target << ", causing " << attackDamage << " points of damage. Energy left: " << energyPoints << std::endl;
	}
	else
		std::cout << "[FragTrap] " << name << " cannot attack (insufficient energy points)." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "[FragTrap] " << name << " requests a high five!" << std::endl;
}