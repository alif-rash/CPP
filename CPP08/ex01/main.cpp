/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:25:39 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 15:47:42 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest: " << sp.longestSpan() << std::endl;

    try
    {
        sp.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Span range(5);
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    range.addNumber(numbers.begin(), numbers.end());

    std::cout << "Range shortest: " << range.shortestSpan() << std::endl;
    std::cout << "Range longest: " << range.longestSpan() << std::endl;

    return 0;
}
