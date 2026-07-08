/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:08:36 by marvin            #+#    #+#             */
/*   Updated: 2026/07/06 16:24:28 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main() {
    Bureaucrat highRank("Alice", 10);
    Bureaucrat lowRank("Bob", 140);
    Form contract("Standard Contract", 50, 25);

    std::cout << contract << std::endl;

    // Failure Case: Bob's grade (140) is too low for the form (50)
    std::cout << "--- Bob tries to sign ---" << std::endl;
    lowRank.signForm(contract);
    std::cout << contract << std::endl;

    // Success Case: Alice's grade (10) is high enough for the form (50)
    std::cout << "--- Alice tries to sign ---" << std::endl;
    highRank.signForm(contract);
    std::cout << contract << std::endl;

    return 0;
}