/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:22:00 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/09 00:22:00 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called\n";
    *this = copy;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &src) {
    std::cout << "Copy assignment operator called\n";
    if (this != &src)
        this->_fixedPointValue = src.getRawBits();
    return *this;
}

Fixed::Fixed(int const intValue) {
    std::cout << "Int constructor called\n";
    this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(float const floatValue) {
    std::cout << "Float constructor called\n";
    this->_fixedPointValue = roundf(floatValue * (1 << this->_fractionalBits));
}

float Fixed::toFloat(void) const {
    return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> this->_fractionalBits;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    this->_fixedPointValue = raw;
}

bool Fixed::operator>(Fixed fixed) const {
    return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(Fixed fixed) const {
    return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(Fixed fixed) const {
    return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(Fixed fixed) const {
    return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(Fixed fixed) const {
    return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(Fixed fixed) const {
    return this->toFloat() != fixed.toFloat();
}

float Fixed::operator+(Fixed fixed) const {
    return this->toFloat() + fixed.toFloat();
}

float Fixed::operator-(Fixed fixed) const {
    return this->toFloat() - fixed.toFloat();
}

float Fixed::operator*(Fixed fixed) const {
    return this->toFloat() * fixed.toFloat();
}

float Fixed::operator/(Fixed fixed) const {
    if (fixed.toFloat() == 0) {
        std::cerr << "Error: Division by zero\n";
        return 0;
    }
    return this->toFloat() / fixed.toFloat();
}

Fixed Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    this->_fixedPointValue++;
    return temp;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    this->_fixedPointValue--;
    return temp;
}

Fixed& Fixed::min(Fixed& first, Fixed& second) {
    return (first < second) ? first : second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second) {
    return (first < second) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second) {
    return (first > second) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second) {
    return (first > second) ? first : second;
}

std::ostream &operator<<(std::ostream &os, const Fixed& other) {
    os << other.toFloat();
    return os;
}
