/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:07:46 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 15:52:18 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

class NotFoundException : public std::exception
{
    public :
        virtual const char *what() const throw()
        {
            return ("Number not found");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return (it);
}

#endif