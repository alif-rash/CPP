/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:25:29 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 13:27:14 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef span_HPP
#define span_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class span
{
    private:
        unsigned int max_size;
        std::vector<int> numbers;
    public:
        span();
        span(unsigned int n);
        span(const span &other);
        span &operator=(const span &other);
        ~span();

        void addNumber(int number);
        unsigned int shortestspan();
        unsigned int longestspan();

        class spanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class NotEnoughNumbersException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
        template <typename T>
        void addNumber(T begin, T end)
        {
            if (numbers.size() + std::distance(begin, end) > max_size)
                throw spanFullException();
            numbers.insert(numbers.end(), begin, end);
        }

        

};

#endif