/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 02:00:20 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/28 09:54:20 by raalifa          ###   ########.fr       */
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
		Fixed(const int i_value);
		Fixed (const float f_value);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();


		int 	toInt(void) const;
		float 	toFloat(void) const;

		int 	getRawBits(void) const;
		void 	setRawBits(int const raw);

};

std::ostream &operator<<(std::ostream &os, const Fixed& F);

#endif