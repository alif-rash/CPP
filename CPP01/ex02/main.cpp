/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 08:34:26 by raalifa           #+#    #+#             */
/*   Updated: 2026/02/07 08:34:26 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string val = "HI THIS IS BRAIN";
	std::string *valPTR = &val;
	std::string &valREF = val;

	std::cout << "The memory address of the string:\t " << &val << std::endl;
	std::cout << "The memory address of the stringPTR:\t " << valPTR << std::endl;
	std::cout << "The memory address of the stringREF:\t " << &valREF << std::endl << std::endl;
	std::cout << "The value of the string:\t " << val << std::endl;
	std::cout << "The value pointed to by stringPTR:\t " << *valPTR << std::endl;
	std::cout << "The value referred to by stringREF:\t " << valREF << std::endl;


}