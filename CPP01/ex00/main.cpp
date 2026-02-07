/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 08:30:52 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/07 08:30:52 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombie1;

	zombie1 = newZombie("Zombie1");
	zombie1->announce();
	delete zombie1;
	randomChump("Zombie2");
	return 0;
}