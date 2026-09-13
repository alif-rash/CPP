/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 15:57:28 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/13 14:15:03 by raalifa          ###   ########.fr       */
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
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch(std::exception &) {}
    
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch(std::exception &){}
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch(std::exception &){}
    std::cout << "Unknown type" << std::endl;
}


int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL)));


    for (int i = 0; i < 4; i++)
    {
        std::cout << "Iteration [" << i + 1 << "] " << std::endl;
        Base* obj = generate();

        std::cout << "Pointer: ";
        identify(obj);

        std::cout << "Reference: ";
        identify(*obj);

        delete obj;
        std::cout << std::endl;
    }   

    return 0;
}