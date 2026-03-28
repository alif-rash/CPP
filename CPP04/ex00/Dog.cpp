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
	std::cout << "[Dog] default constructor" << std::endl;
}

Dog::Dog(const std::string& type) : Animal(type)
{
	std::cout << "[Dog] type constructor (type=" << this->type << ")" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy)
{
	std::cout << "[Dog] copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[Dog] destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] sound: Woof!" << std::endl;
}
