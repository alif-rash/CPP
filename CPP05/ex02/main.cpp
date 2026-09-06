/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:08:36 by marvin            #+#    #+#             */
/*   Updated: 2026/09/06 12:45:12 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    srand(time(NULL));
    std::cout << "==================================================" << std::endl;
    {
        Bureaucrat lowRank("LowRank_Bob", 147);
        Bureaucrat midRank("MidRank_Jim", 140);
        Bureaucrat highRank("HighRank_Eva", 130);
        ShrubberyCreationForm shrub("home");

        std::cout << shrub << std::endl;
        lowRank.signForm(shrub);
        midRank.signForm(shrub);
        midRank.executeForm(shrub);
        highRank.executeForm(shrub);
    }

    std::cout << "\n==================================================" << std::endl;
    {
        Bureaucrat assistant("Assistant_Dwight", 60);
        Bureaucrat manager("Manager_Michael", 40);
        RobotomyRequestForm robot("Claptrap");
        std::cout << robot << std::endl;
        manager.executeForm(robot);
        assistant.signForm(robot);
        manager.executeForm(robot);
        manager.executeForm(robot);
    }

    std::cout << "\n==================================================" << std::endl;
    {
        Bureaucrat VP("VicePresident", 10);
        Bureaucrat President("President_Zaphod", 2);
        PresidentialPardonForm pardon("Marvin");

        std::cout << pardon << std::endl;
        VP.signForm(pardon);
        President.executeForm(pardon);
    }

    return 0;
}