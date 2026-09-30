/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:31:58 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/30 18:07:43 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
    private:
        T           *arr;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();


        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;
        unsigned int size() const;

       class OutOfBoundsException : public std::exception{
        public:
            virtual const char *what() const throw();
       };

};
#include "Array.tpp"
#endif