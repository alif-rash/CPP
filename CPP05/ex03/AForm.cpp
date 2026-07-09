/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 11:54:47 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/08 11:54:47 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, const int gradeToSign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{ 
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

AForm& AForm::operator=(const AForm& copy)
{
    if (this!= &copy)
    {
        this->isSigned = copy.isSigned;
    }
    return *this;
}

AForm::~AForm() {}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIsSigned() const
{
    return this->isSigned;
}

int AForm::getGradeToSign() const
{
    return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return this->gradeToExecute;
}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char * AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

void AForm::checkExecution(Bureaucrat const &executor) const
{
    if (!isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > gradeToExecute)
        throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& f)
{
    out << "Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: " << f.getGradeToSign() << ", Grade to Execute: " << f.getGradeToExecute();
    return out;
}