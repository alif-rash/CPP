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
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string& type) : type(type)
{
	std::cout << "Animal of type " << type << " called\n";
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal of type " << type << " destructor called\n";
}

void Animal ::makeSound() const
{
	std::cout << "Animal of type " << type << " makes a sound! (general)\n";
}

void Animal::setType(const std::string& type)
{
	this->type = type;
}

const std::string &Animal::getType() const
{
	return (this->type);
}

