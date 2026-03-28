/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:00:20 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/28 09:54:06 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &rhs)
		this->value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

Fixed::Fixed(const int i_value)
{
	std::cout << "Int constructor called" << std:: endl;
	this->value = i_value << fractional_bit;
}

Fixed::Fixed(const float f_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(f_value * (1 << fractional_bit));
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->value) / (1 << fractional_bit);
}

int Fixed::toInt(void) const
{
	return (this->value >> fractional_bit);
}

std::ostream &operator<<(std::ostream &os, const Fixed& F)
{
	os << F.toFloat();
	return (os);
}
