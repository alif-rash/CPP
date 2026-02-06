/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 22:10:44 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/05 22:10:44 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    std::string level;
    Harl harl;

    if (ac != 2)
    {
        std::cout << "Usage: ./Harl <level>\n";
        return 1;
    }
    level = av[1];
    harl.complain(level);
    return (0);
}