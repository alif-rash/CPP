/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:50:06 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/22 12:50:06 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool skipSign(const std::string& input, size_t& i)
{
    i = 0;
    if (input[0] == '-' || input[0] == '+')
    {
        if (input.length() == 1)
            return false;
        i = 1;
    }
    return true;
}

bool isChar(const std::string& input)
{
    if (input.length() == 1 && !std::isdigit(input[0]))
        return true;
    else if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        return true;
    return false;
}

bool isInt(const std::string& input)
{
    errno = 0;
    size_t i = 0;
    if (!skipSign(input, i))
        return false;
    while (i < input.length())
    {
        if (!std::isdigit(input[i]))
            return false;
        i++;
    }
    long value = std::strtol(input.c_str(), NULL, 10);
    if (errno == ERANGE)
        return false;
    if (value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max())
        return false;
    return true;
}

bool isPseudoFloat(const std::string& input)
{
    return (input == "nanf" || input == "+inff" || input == "-inff");
}

bool isPseudoDouble(const std::string& input)
{
    return (input == "nan" || input == "+inf" || input == "-inf");
}

bool isFloat(const std::string& input)
{
    size_t i = 0;
    bool dotFound = false;
    bool digFound = false;
    if (!skipSign(input, i))
        return false;
    while (i < input.length())
    {
        if (std::isdigit(input[i]))
            digFound = true;
        else if (input[i] == '.' && !dotFound)
            dotFound = true;
        else if (input[i] == 'f' && i == input.length() - 1)
            return (dotFound && digFound);
        else
            return false;
        i++;
    }
    return false;
}

bool isDouble(const std::string& input)
{
    size_t i = 0;
    bool dotFound = false;
    bool digFound = false;
    if (!skipSign(input, i))
        return false;
    while (i < input.length())
    {
        if (std::isdigit(input[i]))
            digFound = true;
        else if (input[i] == '.' && !dotFound)
            dotFound = true;
        else
            return false;
        i++;
    }
    return (dotFound && digFound);
}

Type detectType(const std::string& input)
{
    if (isChar(input))
        return CHAR;
    else if (isInt(input))
        return INT;
    else if (isFloat(input) || isPseudoFloat(input))
        return FLOAT;
    else if (isDouble(input) || isPseudoDouble(input))
        return DOUBLE;
    else
        return UNKNOWN;
}