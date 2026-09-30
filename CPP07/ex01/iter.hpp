/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:09:45 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/30 18:03:51 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>
#include <string>


template <typename T>
void print(const T& value)
{
    std::cout << value << std::endl;
}

template <typename T_array, typename T_func>
void iter(T_array *array, size_t len, T_func function)
{
    if(!array)
        return;
    for (size_t i = 0; i < len; i++)
        function(array[i]);
}

template <typename T_array, typename T_func>
void iter(const T_array *array, const size_t len, T_func function)
{
    if(array == NULL)
        return;
    for (size_t i = 0; i < len; i++)
        function(array[i]);
}


#endif