/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:56:54 by raalifa           #+#    #+#             */
/*   Updated: 2026/09/13 13:55:45 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

bool isInf(double value)
{
    return (value == std::numeric_limits<double>::infinity() || 
            value == -std::numeric_limits<double>::infinity());
}

void printCharResult(double value)
{
    if (isInf(value) ||
        value != value ||
        value < std::numeric_limits<char>::min() ||
        value > std::numeric_limits<char>::max())
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void printIntResult(double value)
{
    if (isInf(value) ||
        value != value ||
        value < static_cast<double>(std::numeric_limits<int>::min()) ||
        value > static_cast<double>(std::numeric_limits<int>::max()))
    {
        std::cout << "int: impossible" << std::endl;
        return;
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloatResult(double value)
{
    if (value != value)
    {
        std::cout << "float: nanf" << std::endl;
        return;
    }
    if (isInf(value))
    {
        if (value > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
        return;
    }
    if (value < -std::numeric_limits<float>::max() ||
        value > std::numeric_limits<float>::max())
    {
        std::cout << "float: impossible" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
}

void printDoubleResult(double value)
{
    if (value != value)
    {
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (isInf(value))
    {
        if (value > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
        return;
    }
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << value << std::endl;
}

void printError()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

void printAllResults(double value)
{
    printCharResult(value);
    printIntResult(value);
    printFloatResult(value);
    printDoubleResult(value);
}

void ScalarConverter::convert(const std::string& input)
{
    if (input.empty())
    {
        printError();
        return;
    }
    Type type = detectType(input);
    switch (type)
    {
        case CHAR:
            printAllResults(static_cast<double>(input.length() == 1 ? input[0] : input[1]));
            break;
        case INT:
            printAllResults(static_cast<double>(std::strtol(input.c_str(), NULL, 10)));
            break;
        case FLOAT:
            if (input == "nanf" )
                printAllResults(std::numeric_limits<float>::quiet_NaN());
            else if (input == "+inff" || input == "inff")
                printAllResults(std::numeric_limits<float>::infinity());
            else if (input == "-inff")
                printAllResults(-std::numeric_limits<float>::infinity());
            else
                printAllResults(static_cast<double>(static_cast<float>(std::strtod(input.c_str(), NULL)))); 
            break;
        case DOUBLE:
            printAllResults(std::strtod(input.c_str(), NULL));
            break;
        default:
            printError();
            break;
    }
}
