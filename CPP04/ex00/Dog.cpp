/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:40:30 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:40:30 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const std::string& type) : Animal(type)
{
	std::cout << "Dog of type " << type << " constructor called\n";
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator=(const Dog& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog of type " << type << " destructor called\n";
}

void Dog::makeSound() const
{
	std::cout << "Dog of type " << type << " says: Woof!\n";
}
