/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:25:39 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 13:40:38 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <vector>

int main()
{
    span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestspan() << std::endl;
    std::cout << "Longest: " << sp.longestspan() << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    span range(5);
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    range.addNumber(numbers.begin(), numbers.end());

    std::cout << "Range shortest: " << range.shortestspan() << std::endl;
    std::cout << "Range longest: " << range.longestspan() << std::endl;

    return 0;
}
