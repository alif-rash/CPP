/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:48:45 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/30 17:46:11 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
T const& min(const T &a, const T &b)
{
    return (a < b ? a : b);
}

template <typename T>
T const& max(const T &a, const T &b)
{
    return (a > b ? a : b);
}

#endif