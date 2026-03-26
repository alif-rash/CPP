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
        scav.attack("Enemy");     // 20 Damage [cite: 166]
        scav.guardGate();         // Special [cite: 168]
        scav.takeDamage(50);
    }
    std::cout << std::endl;

    {
        std::cout << "--- FRAGTRAP TEST ---" << std::endl;
        FragTrap frag("Party");
        frag.attack("Dummy");     // 30 Damage [cite: 188]
        frag.highFivesGuys();     // Special [cite: 190]
        frag.beRepaired(20);
    }
    std::cout << std::endl;

    {
        std::cout << "--- DEEP COPY TEST ---" << std::endl;
        FragTrap original("Original");
        FragTrap copy(original);
        copy = original;
    }

    return 0;
}