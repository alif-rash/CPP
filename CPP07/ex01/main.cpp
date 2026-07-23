/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:09:49 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/22 18:09:49 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Integer Array:" << std::endl;
    iter(intArray, 5, print<int>);

    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "42", "Abu Dhabi"};
    std::cout << "String Array:" << std::endl;
    iter(strArray, 4, print<std::string>);

    return 0;
}