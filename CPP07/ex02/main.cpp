/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 18:31:54 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/30 18:36:02 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <cstdlib>

int main()
{
    Array<int> a(3);

    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    std::cout << a[0] << std::endl;
    std::cout << a[1] << std::endl;
    std::cout << a[2] << std::endl;

    std::cout << "Size: " << a.size() << std::endl;

    Array<int> b = a;
    b[0] = 100;

    std::cout << "a[0]: " << a[0] << std::endl;
    std::cout << "b[0]: " << b[0] << std::endl;

    try
    {
        std::cout << a[5] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Array<std::string> words(2);

    words[0] = "Hello";
    words[1] = "42";

    std::cout << words[0] << std::endl;
    std::cout << words[1] << std::endl;

    const Array<int> c(2);

    std::cout << c[0] << std::endl;
    std::cout << c[1] << std::endl;

    return 0;
}