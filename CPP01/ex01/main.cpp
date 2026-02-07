/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 08:34:16 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/07 08:34:16 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;
	Zombie* horde = zombieHorde(N, "Horde");
	if (!horde)
		return (1);
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}