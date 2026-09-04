/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:07:19 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/30 15:07:19 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
		return (1);
	}
    (void)av; 
	try
	{
		BitcoinExchange exchange;
		exchange.loadDatabase("data.csv");
		// exchange.processInputFile(av[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}