/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 22:51:15 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 22:51:15 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "[WrongCat] default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy)
{
	*this = copy;
	std::cout << "[WrongCat] copy constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	if (this == &src)
		return (*this);
	this->type = src.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WrongCat] destructor" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "[WrongCat] sound: Meow? (wrong polymorphism demo)" << std::endl;
}

