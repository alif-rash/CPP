/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 21:25:34 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/28 21:25:34 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

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

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (numbers.size() + std::distance(begin, end) > max_size)
        throw SpanFullException();
    numbers.insert(numbers.end(), begin, end); 
}

unsigned int Span::shortestSpan()
{
    if(numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> v = numbers;
    std::sort(v.begin(), v.end());
     int min = v[1] - v[0];
    for (size_t i = 1; i < v.size() - 1; i++)
    {
        if (v[i] - v[i - 1] < min)
            min = v[i] - v[i - 1];
    }
    return min;
}

unsigned int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw NotEnoughNumbersException();
    std::vector<int> v = numbers;
    std::sort(v.begin(), v.end());
    return v.back() - v.front();
}



const char *Span::SpanFullException::what() const throw()
{
    return "Container is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
    return "Not enough numbers to find a span";
}

