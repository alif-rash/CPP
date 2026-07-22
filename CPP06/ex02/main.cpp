/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:57:28 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/22 15:57:28 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <iostream>
#include <exception>
#include <ctime>

Base *generate()
{
    int randomNum = rand() % 3;
    switch (randomNum)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(std::exception& e) 
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
            return;
        }
        catch(std::exception &e)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
                return;
            }
            catch(std::exception &e)
            {
                std::cout << "Unknown type" << std::endl;
                return;
            }
        }
    }
}


int main()
{
    std::srand(std::time(NULL));

    Base* obj = generate();

    std::cout << "Pointer: ";
    identify(obj);

    std::cout << "Reference: ";
    identify(*obj);

    delete obj;

    return 0;
}