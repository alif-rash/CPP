/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:13:57 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:13:57 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] default constructor (type=" << type << ")" << std::endl;
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "[Animal] type constructor (type=" << this->type << ")" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << "[Animal] copy constructor (type=" << type << ")" << std::endl;
}

Animal &Animal::operator=(const Animal& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "[Animal] destructor (type=" << type << ")" << std::endl;
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}

const std::string &Animal::getType() const
{
	return (this->type);
}

