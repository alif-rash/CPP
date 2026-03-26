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
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string& type) : type(type)
{
	std::cout << "WrongAnimal of type " << type << " constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal of type " << type << " destructor called\n";
}

void WrongAnimal ::makeSound() const
{
	std::cout << "WrongAnimal of type " << type << " makes a sound! (general)\n";
}

void WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

const std::string &WrongAnimal::getType() const
{
	return (this->type);
}
