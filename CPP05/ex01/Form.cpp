/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:01:56 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/06 12:38:54 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) 
{ 
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy) : name(copy.name), isSigned(copy.isSigned), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {}

Form& Form::operator=(const Form& copy)
{
    if (this!= &copy)
    {
        this->isSigned = copy.isSigned;
    }
    return *this;
}

Form::~Form() {}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    else
        throw GradeTooLowException();
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getIsSigned() const
{
    return this->isSigned;
}

int Form::getGradeToSign() const
{
    return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
    return this->gradeToExecute;
}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char * Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& f)
{
    out << "Name: " << f.getName() << ", Signed: " << (f.getIsSigned() ? "Yes" : "No") << ", Grade to Sign: " << f.getGradeToSign() << ", Grade to Execute: " << f.getGradeToExecute() << ".";
    return out;
}