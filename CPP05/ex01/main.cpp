/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:08:36 by marvin            #+#    #+#             */
/*   Updated: 2026/09/06 11:28:30 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    Bureaucrat alice("Alice", 10);
    Bureaucrat bob("Bob", 100);
    Form contract("Contract", 50, 25);

    std::cout << contract << std::endl;

    std::cout << "\n--- Bob tries to sign ---" << std::endl;
    bob.signForm(contract);
    std::cout << "\n--- Form after Bob's attempt ---" << std::endl;
    std::cout << contract << std::endl;

    
    std::cout << "\n--- Alice tries to sign ---" << std::endl;
    alice.signForm(contract);
    std::cout << "\n--- Form after Alice's attempt ---" << std::endl;
    std::cout << contract << std::endl;

    return 0;
}