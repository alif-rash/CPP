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
#include "Brain.hpp"

Dog::Dog() : Animal("Dog"), brain(NULL)
{
	this->brain = new Brain();
	std::cout << "[Dog] default constructor" << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy), brain(NULL)
{
	if (copy.brain)
		this->brain = new Brain(*copy.brain);
	std::cout << "[Dog] copy constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
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
	std::cout << "[Dog] copy assignment operator" << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "[Dog] destructor" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "[Dog] sound: Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->brain);
}