/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:52:02 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/06 13:52:02 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;
    public:
        Form();
        Form(const std::string name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();

        void        beSigned(const Bureaucrat& b);

        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        class GradeTooHighException : public std::exception 
        {
            public:
                virtual const char * what() const throw();
        };

        class GradeTooLowException : public std::exception 
        {
            public:
                virtual const char * what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Form& f);

#endif