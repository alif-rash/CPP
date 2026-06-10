/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:00:33 by marvin            #+#    #+#             */
/*   Updated: 2026/06/10 23:00:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) : name(copy.name), grade(copy.grade)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
    std::cout << "Bureaucrat copy assignment operator called" << std::endl;
    if (this != &copy)
        this->grade = copy.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw GradeTooHighException();
    grade--;
}   

void Bureaucrat::decrementGrade(){
    if (grade + 1 > 150)
        throw GradeTooLowException();
    grade++;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("grade too high!!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("grade too low!!");
}

std::ostream& operator<<(std::ostream& out, Bureaucrat& b)
{
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return out;
}
