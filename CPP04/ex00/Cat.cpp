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
	std::cout << "[Cat] default constructor" << std::endl;
}

Cat::Cat(const std::string& type) : Animal(type)
{
	std::cout << "[Cat] type constructor (type=" << this->type << ")" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy)
{
	std::cout << "[Cat] copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] sound: Meow!" << std::endl;
}

