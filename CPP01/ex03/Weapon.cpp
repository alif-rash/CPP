/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 10:34:11 by raalifa           #+#    #+#             */
/*   Updated: 2026/01/29 10:34:11 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	std::cout << "Default Weapon created." << std::endl;
}

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::~Weapon()
{
	std::cout << "Weapon of type " << this->type << " is being destroyed." << std::endl;
}

std::string Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(std::string newType)
{
	this->type = newType;
}