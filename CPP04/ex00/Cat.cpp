/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:29:32 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:29:32 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const std::string& type) : Animal(type)
{
	std::cout << "Cat of type " << type << " constructor called\n";
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator=(const Cat& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat of type " << type << " destructor called\n";
}

void Cat::makeSound() const
{
	std::cout << "Cat of type " << type << " says: Meow!\n";
}

