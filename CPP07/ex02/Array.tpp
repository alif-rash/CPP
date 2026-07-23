/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 19:31:00 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/22 19:31:00 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : arr(NULL), size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]()), size(n) {}

template <typename T>
Array<T>::Array(const Array& other) : arr(new T[other.size]()), size(other.size) 
{
    for (unsigned int i = 0; i < size; i++)
        arr[i] = other.arr[i]; 
}
template <typename T>
Array<T>::~Array()
{
    delete [] arr;
}
template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete [] arr;
        size = other.size;
        arr = new T[size]();
        for (unsigned int i = 0; i < size; i++)
            arr[i] = other.arr[i];
        
    }
    return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
    if (i >= size)
        throw OutOfBoundsException();
    return(arr[i]);
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
    if (i >= size)
        throw OutOfBoundsException();
    return(arr[i]);
}

template <typename T>
unsigned int Array<T>::getSize() const
{
    return (size);
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
    return ("Index out of bounds");
}

#endif