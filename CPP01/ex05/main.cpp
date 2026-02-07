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

int main()
{
    Harl harl;

    std::cout << "Harl's complaints:\n";
    
    std::cout << "Testing with known levels:\n";
    std::cout << "-------------------------\n";
    std::cout << "[DEBUG]\n";
    harl.complain("DEBUG");
    std::cout << std::endl << "[INFO]\n";
    harl.complain("INFO");
    std::cout << std::endl << "[WARNING]\n";
    harl.complain("WARNING");
    std::cout << std::endl << "[ERROR]\n";
    harl.complain("ERROR");
    
    std::cout << "\nTesting with an unknown level:\n";
    std::cout << "-------------------------\n";
    harl.complain("UNKNOWN");

    return 0;
}