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

#include "ClapTrap.hpp"

int main()
{
	ClapTrap alpha("Alpha");
	ClapTrap beta(alpha);
	ClapTrap gamma;

	gamma = alpha;

	std::cout << "\n=== Basic Actions ===" << std::endl;
	alpha.attack("Target-1");
	beta.takeDamage(5);
	gamma.beRepaired(3);

	std::cout << "\n=== Energy Drain ===" << std::endl;
	for (int i = 0; i < 11; i++)
		alpha.attack("Dummy");

	std::cout << "\n=== Destroyed State ===" << std::endl;
	beta.takeDamage(100);
	beta.beRepaired(2);
	beta.attack("Target-2");

	std::cout << std::endl;


	return 0;
}