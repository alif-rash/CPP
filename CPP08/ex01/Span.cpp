/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:25:34 by raalifa           #+#    #+#             */
/*   Updated: 2026/10/02 15:47:42 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : max_size(0) {}

Span::Span(unsigned int n) : max_size(n) {}

Span::Span(const Span &other) : max_size(other.max_size), numbers(other.numbers) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        max_size = other.max_size;
        numbers = other.numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (numbers.size() >= max_size)
        throw SpanFullException();
    numbers.push_back(number);
}

unsigned int Span::shortestSpan()
{
    if(numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> v = numbers;
    std::sort(v.begin(), v.end());
    long min =static_cast<long> (v[1]) - static_cast<long>(v[0]);
    for (size_t i = 1; i < v.size(); i++)
    {
        long diff = static_cast<long>(v[i]) - static_cast<long>(v[i - 1]);
        if (diff < min)
            min = diff;
    }
    return static_cast<unsigned int>(min);
}

unsigned int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> v = numbers;
    std::sort(v.begin(), v.end());
    return static_cast<unsigned int> (static_cast<long>(v.back()) - static_cast<long>(v.front()));
}



const char *Span::SpanFullException::what() const throw()
{
    return "Container is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to find a Span";
}

