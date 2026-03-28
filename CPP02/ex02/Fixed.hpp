/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:22:10 by raalifaa           #+#    #+#             */
/*   Updated: 2026/03/28 09:53:11 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int 				value;
		static const int 	fractional_bit = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& src);
		~Fixed();

		Fixed(const int i_value);
		Fixed (const float f_value);

		bool operator>(const Fixed& n) const;
		bool operator<(const Fixed& n) const;
		bool operator>=(const Fixed& n) const;
		bool operator<=(const Fixed& n) const;
		bool operator==(const Fixed& n) const;
		bool operator!=(const Fixed& n) const;

		Fixed operator+(const Fixed& n) const;
		Fixed operator-(const Fixed& n) const;
		Fixed operator*(const Fixed& n) const;
		Fixed operator/(const Fixed& n) const;

		Fixed& operator++();
		Fixed operator++(int);
		Fixed& operator--();
		Fixed operator--(int);

		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

		float toFloat(void) const;
		int toInt(void) const;

		int getRawBits(void) const;
		void setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &os, const Fixed& F);

#endif