/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 22:31:01 by marvin            #+#    #+#             */
/*   Updated: 2026/07/09 10:19:51 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

class AForm;

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();

        void executeForm(AForm& f);
        
        void incrementGrade();
        void decrementGrade();

        std::string getName() const;
        int         getGrade() const;
        
        void signForm(AForm& f) const;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char * what() const throw();
        };
};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif