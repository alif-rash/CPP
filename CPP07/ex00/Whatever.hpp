/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:48:45 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/22 16:48:45 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp;

    temp = a;
    a = b;
    b = temp;
}
template <typename T>
T const& min(T &a, T &b)
{
    if (a == b)
        return b;
    return (a < b ? a : b);
}

template <typename T>
T const& max(T &a, T &b)
{
    if (a == b)
        return b;
    return (a > b ? a : b);
}

#endif