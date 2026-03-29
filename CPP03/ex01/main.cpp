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
    std::cout << "\n Basic ClapTrap behavior" << std::endl;
    {
        ClapTrap clap("Clappy");
        clap.attack("Target-1");
        clap.takeDamage(5);
        clap.beRepaired(3);
    }

    std::cout << "\n ScavTrap specific behavior" << std::endl;
    {
        ScavTrap scav("Scavvy");
        scav.attack("Target-2");
        scav.guardGate();
        scav.takeDamage(99);
        scav.beRepaired(10);
        scav.guardGate();
    }

    std::cout << "\n Energy depletion check" << std::endl;
    {
        ScavTrap tiny("Tiny");
        for (int i = 0; i < 51; i++)
            tiny.attack("Wall");
    }
    return (0);
}