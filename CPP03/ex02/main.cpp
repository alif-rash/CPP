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
#include "FragTrap.hpp"

int main()
{
    {
        std::cout << "--- CLAPTRAP TEST ---" << std::endl;
        ClapTrap clap("Basic");
        clap.attack("Target");
        clap.takeDamage(5);
        clap.beRepaired(5);
    }
    std::cout << std::endl;

    {
        std::cout << "--- SCAVTRAP TEST ---" << std::endl;
        ScavTrap scav("Guardian");
        scav.attack("Enemy");  
        scav.guardGate(); 
        scav.takeDamage(50);
    }
    std::cout << std::endl;

    {
        std::cout << "--- FRAGTRAP TEST ---" << std::endl;
        FragTrap frag("someone");
        frag.attack("whoever"); 
        frag.highFivesGuys();
        frag.beRepaired(20);
    }
    std::cout << std::endl;
    return 0;
}