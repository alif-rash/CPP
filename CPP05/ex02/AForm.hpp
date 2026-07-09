/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 11:54:55 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/08 11:54:55 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;
    public:
        AForm();
        AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        virtual ~AForm();

        void        beSigned(const Bureaucrat& b);
        virtual void execute(Bureaucrat const &executor) const = 0;
        std::string getName() const;
        bool        getIsSigned() const;
        int         getGradeToSign() const;
        int         getGradeToExecute() const;

        void checkExecution(Bureaucrat const &executor) const;
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

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif