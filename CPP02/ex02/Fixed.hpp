/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 00:22:10 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/09 00:22:10 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

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

        bool operator>(Fixed fixed)const;
        bool operator<(Fixed fixed)const;
        bool operator>=(Fixed fixed)const;
        bool operator<=(Fixed fixed)const;
        bool operator==(Fixed fixed)const;
        bool operator!=(Fixed fixed)const;

        float operator+(Fixed fixed)const;
        float operator-(Fixed fixed)const;
        float operator*(Fixed fixed)const;
        float operator/(Fixed fixed)const;

        Fixed operator++(void);
        Fixed operator--(void);

        Fixed operator++(int);
        Fixed operator--(int);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

        static Fixed& min(Fixed& first, Fixed& second);
        static const Fixed& min(const Fixed& first, const Fixed& second);
        static Fixed& max(Fixed& first, Fixed& second);
        static const Fixed& max(const Fixed& first, const Fixed& second);
};
    std::ostream &operator<<(std::ostream &os, const Fixed& other);




#endif