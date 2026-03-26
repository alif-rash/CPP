/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 10:33:20 by raalifa           #+#    #+#             */
/*   Updated: 2026/03/26 10:33:20 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "--- TEST 1: CLAPTRAP BASIC ---" << std::endl;
    {
        ClapTrap clap("Clappy");
        clap.attack("Target1");
        clap.takeDamage(5);
        clap.beRepaired(3);
    }
    std::cout << "\n--- TEST 2: SCAVTRAP INHERITANCE ---" << std::endl;
    {
        ScavTrap scav("Scavvy");
        scav.attack("Target2");   
		scav.guardGate();         
        scav.takeDamage(99);
        scav.beRepaired(10);
    }
    std::cout << "\n--- TEST 3: ENERGY DEPLETION ---" << std::endl;
    {
        ScavTrap tiny("Tiny");
        for (int i = 0; i < 50; i++) 
            tiny.attack("Wall");
        tiny.attack("Wall");
    }
    return 0;
}