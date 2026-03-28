/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:22:10 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/28 09:52:40 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	if(this != &rhs)
		this->value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(){}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int Fixed::getRawBits(void) const
{
	return (this->value);
}

Fixed::Fixed(const int i_value)
{
	this->value = i_value << fractional_bit;
}

Fixed::Fixed(const float f_value)
{
	this->value = roundf(f_value * (1 << fractional_bit));
}

bool Fixed::operator>(const Fixed& n) const
{
	return (this->value > n.getRawBits());
}

bool Fixed::operator<(const Fixed& n) const
{
	return (this->value < n.getRawBits());
}

bool Fixed::operator>=(const Fixed& n) const
{
	return (this->value >= n.getRawBits());
}

bool Fixed::operator<=(const Fixed& n) const
{
	return (this->value <= n.getRawBits());
}

bool Fixed::operator==(const Fixed& n) const
{
	return (this->value == n.getRawBits());
}

bool Fixed::operator!=(const Fixed& n) const
{
	return (this->value != n.getRawBits());
}

Fixed Fixed::operator+(const Fixed& n) const
{
	return (Fixed(this->toFloat() + n.toFloat()));
}

Fixed Fixed::operator-(const Fixed& n) const
{
	return (Fixed(this->toFloat() - n.toFloat()));
}

Fixed Fixed::operator*(const Fixed& n) const
{
	Fixed res;
	res.setRawBits(static_cast<long>(this->value) * static_cast<long>(n.getRawBits()) >> fractional_bit);
	return (res);
}

Fixed Fixed::operator/(const Fixed& n) const
{
	if (n.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / n.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->value++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->value++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->value--;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return ( a > b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
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
