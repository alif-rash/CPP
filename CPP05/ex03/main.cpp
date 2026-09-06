/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:08:36 by marvin            #+#    #+#             */
/*   Updated: 2026/09/06 12:45:27 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    Bureaucrat boss("Boss", 1);
    Intern intern;
    srand(time(NULL));
    
    std::cout << "------------------------------------"<< std::endl;
    AForm *f1 = intern.makeForm("shrubbery creation", "garden");
    AForm *f2 = intern.makeForm("robotomy request", "Bender");
    AForm *f3 = intern.makeForm("presidential pardon", "Arthur Dent");
    AForm *f4 = intern.makeForm("random form", "Nobody");
    std::cout << "------------------------------------"<< std::endl;

    if (f1)
    {
        boss.signForm(*f1);
        boss.executeForm(*f1);
        delete f1;
    }
    std::cout << "------------------------------------"<< std::endl;

    if (f2)
    {
        boss.signForm(*f2);
        boss.executeForm(*f2);
        delete f2;
    }
    std::cout << "------------------------------------"<< std::endl;

    if (f3)
    {
        boss.signForm(*f3);
        boss.executeForm(*f3);
        delete f3;
    }
    std::cout << "------------------------------------"<< std::endl;
    delete f4;
    return 0;
}