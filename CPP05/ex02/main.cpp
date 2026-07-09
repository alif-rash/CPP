/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:08:36 by marvin            #+#    #+#             */
/*   Updated: 2026/07/09 10:28:24 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 150);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    // Try executing before signing
    boss.executeForm(shrub);

    // Sign forms
    boss.signForm(shrub);
    boss.signForm(robot);
    boss.signForm(pardon);

    // Execute with enough grade
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    // Try executing with insufficient grade
    worker.executeForm(pardon);

    return 0;
}