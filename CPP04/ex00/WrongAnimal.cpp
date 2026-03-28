/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:56:32 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:56:32 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "[WrongAnimal] default constructor (type=" << type << ")" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
	std::cout << "[WrongAnimal] type constructor (type=" << this->type << ")" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	std::cout << "[WrongAnimal] copy constructor (type=" << type << ")" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[WrongAnimal] destructor (type=" << type << ")" << std::endl;
}

void WrongAnimal ::makeSound() const
{
	std::cout << "[WrongAnimal] " << type << " sound: <generic wrong-animal sound>" << std::endl;
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

const std::string &WrongAnimal::getType() const
{
	return (this->type);
}
