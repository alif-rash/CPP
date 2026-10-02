/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 08:09:57 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 13:16:25 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

int main()
{
    std::cout << "Vector container\n";
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
    {
        vec.push_back(i);
    }
    std::cout << "Searching for 4 in vector: " ;
    try
    {
        std::cout << *(easyfind(vec, 4)) << " found!" << std::endl;
    }
    catch(const NotFoundException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nDeque container\n";
    std::deque<int> deq;

    for (int i = 0; i < 5; i++)
    {
        deq.push_back(i);
    }
    try
    {
        std::cout << "Searching for 1 in deque: " ;
        std::cout << *(easyfind(deq, 1)) << " found!" << std::endl;
        std::cout << "Searching for 15 in deque: ";
        std::cout << *(easyfind(deq, 15)) << " found!" << std::endl;
    }
    catch(const NotFoundException &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\nList container\n";
    std::list<int> lst;
    for (int i = 0; i < 25; i++)
    {
        lst.push_back(i);
    }
    try
    {
        std::cout << "Searching for 1 in list: ";
        std::cout << *(easyfind(lst, 1)) << " found!" << std::endl;
        std::cout << "Searching for 100 in list: ";
        std::cout << *(easyfind(lst, 100)) << " found!" << std::endl;
    }
    catch(const NotFoundException &e)
    {
        std::cout << e.what() << std::endl;
    }
}