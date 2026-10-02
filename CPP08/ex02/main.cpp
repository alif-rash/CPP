/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:41:56 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 15:53:22 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.push(3);

    std::cout << "Top: " << mstack.top() << std::endl;

    std::cout << "Forward: ";
    for (MutantStack<int>::iterator it = mstack.begin();
         it != mstack.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Reverse: ";
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin();
         it != mstack.rend(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return 0;
}