/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:41:56 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/30 10:41:56 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>
#include "Mutantstack.hpp"

int main()
{
    std::cout << "--- Subject Test (MutantStack) ---" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n--- Verification Test (std::list) ---" << std::endl;
    {
        std::list<int> lstack;
        lstack.push_back(5);
        lstack.push_back(17);
        std::cout << lstack.back() << std::endl; // top() is back() for list
        lstack.pop_back();                        // pop() is pop_back() for list
        std::cout << lstack.size() << std::endl;
        lstack.push_back(3);
        lstack.push_back(5);
        lstack.push_back(737);
        //[...]
        lstack.push_back(0);
        std::list<int>::iterator it = lstack.begin();
        std::list<int>::iterator ite = lstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

	std::cout << "\n--- Reverse Iterator Test ---" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1);
        mstack.push(2);
        mstack.push(3);
        
        std::cout << "Forward:  ";
        for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
            std::cout << *it << " ";
        
        std::cout << "\nReverse:  ";
        for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
            std::cout << *rit << " ";
        std::cout << std::endl;
    }

    return 0;
}