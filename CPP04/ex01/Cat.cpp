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

Cat::Cat() : Animal("Cat"), brain(NULL)
{
	this->brain = new Brain();
	std::cout << "[Cat] default constructor" << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy), brain(NULL)
{
	if (copy.brain)
		this->brain = new Brain(*copy.brain);
	std::cout << "[Cat] copy constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		Brain* newBrain = NULL;
		if (rhs.brain)
			newBrain = new Brain(*rhs.brain);
		delete this->brain;
		this->brain = newBrain;
		this->type = rhs.type;
	}
	std::cout << "[Cat] copy assignment operator" << std::endl;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[Cat] destructor" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "[Cat] sound: Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}