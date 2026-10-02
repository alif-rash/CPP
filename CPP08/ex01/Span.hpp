/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:25:29 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 15:48:02 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

class Span
{
    private:
        unsigned int max_size;
        std::vector<int> numbers;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        unsigned int shortestSpan();
        unsigned int longestSpan();

        class SpanFullException : public std::exception
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
                throw SpanFullException();
            numbers.insert(numbers.end(), begin, end);
        }
};

#endif