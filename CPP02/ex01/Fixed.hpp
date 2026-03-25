/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:03:42 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/09 00:03:42 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        Fixed(int const intValue);
        Fixed(float const floatValue);
        Fixed(const Fixed& other);
        ~Fixed();

        Fixed& operator=(const Fixed& other);

        float toFloat(void) const;
        int toInt(void) const;
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
    };
    std::ostream &operator<<(std::ostream &os, const Fixed& other);

#endif