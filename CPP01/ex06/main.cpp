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
	Harl harl;

	if (ac != 2)
	{
		std::cout << "Usage: ./harlFilter <level>\n";
		return 1;
	}
	harl.complain(av[1]);
	return (0);
}