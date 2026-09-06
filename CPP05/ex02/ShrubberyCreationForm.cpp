/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 21:03:32 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/06 12:47:16 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
    if (this != &copy)
    {
        AForm::operator=(copy);
        this->target = copy.target;
    }
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    checkExecution(executor);
    std::ofstream outfile((target + "_shrubbery").c_str());
    if (!outfile)
    {
        std::cerr << "Error: Could not create file \n";
        return;
    }
    outfile << "      /\\" << std::endl;
    outfile << "     /**\\" << std::endl;
    outfile << "    /****\\" << std::endl;
    outfile << "   /******\\" << std::endl;
    outfile << "  /        \\" << std::endl;
    outfile << " /    ()    \\" << std::endl;
    outfile << "/____________\\" << std::endl;
    outfile << "      ||" << std::endl;
    outfile << "      ||" << std::endl;
    outfile.close();


}