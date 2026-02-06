/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 22:06:57 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/05 22:06:57 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {};
Harl::~Harl() {};

void Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!\n" << std::endl;
}

void Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i;

    i = 0;
    while (i < 4 && level != levels[i])
        i++;
    switch(i)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            this->debug();
            //fallthrough
	    case 1:
            std::cout << "[ INFO ]" << std::endl;
	    	this->info();
            //fallthrough
	    case 2:
            std::cout << "[ WARNING ]" << std::endl;
	    	this->warning();
            //fallthrough
	    case 3:
            std::cout << "[ ERROR ]" << std::endl;
	    	this->error();
	    	break;
	    default:
	    	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return;
    
}