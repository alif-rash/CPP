/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 10:45:45 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/06 12:48:51 by raalifa          ###   ########.fr       */
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

static AForm* makePresident(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

static AForm* makeRobot(const std::string &target)
{
    return new RobotomyRequestForm(target);
}

static AForm* makeShrubbery(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    AForm *(*forms[])(const std::string&) = {&makeShrubbery, &makePresident, &makeRobot};
    std::string formNames[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i](target);
        }
    }
    std ::cout << "Intern cannot create " << formName << std::endl;
    return NULL;
}

