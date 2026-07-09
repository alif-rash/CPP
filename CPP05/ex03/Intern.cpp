/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:45:45 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/09 10:45:45 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy)
{
    (void)copy;
}

Intern& Intern::operator=(const Intern & copy)
{
    (void)copy;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    int i;
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    i = 0;
    while (i < 3 && formName != formNames[i])
        i++;
    switch(i)
    {
        case 0:
            std::cout << "Intern creates " << formName << std::endl; 
            return (new ShrubberyCreationForm(target));
        case 1:
            std::cout << "Intern creates " << formName << std::endl; 
            return (new RobotomyRequestForm(target));
        case 2:
            std::cout << "Intern creates " << formName << std::endl; 
            return (new PresidentialPardonForm(target));
        default:
            std::cout << "Intern cannot create " << formName << std::endl;
            return (NULL);
    }

}