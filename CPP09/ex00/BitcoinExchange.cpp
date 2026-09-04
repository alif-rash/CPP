/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:05:00 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/30 15:05:00 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iomanip>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    this->exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        this->exchangeRates = other.exchangeRates;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        start++;
    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        end--;
    return str.substr(start, end-start);
}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: Could not open database file.");
    }

    std::string line;
    if(!std::getline(file, line) || trim(line) != "date,exchange_rate")
    {
        throw std::runtime_error("Error: Invalid database file format.");
    }
    int lineNum = 2;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t commaPos = line.find(',');
        std::string date = line.substr(0, commaPos);
        double value = std::strtod(line.substr(commaPos + 1).c_str(), NULL);
        exchangeRates[date] = value;
        lineNum++;
    }
    file.close();
}

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: Could not open input file.");
    }
    std::string line;
    if (!std::getline(file, line) || trim(line) != "date | value")
    {
        throw std::runtime_error("Error: Invalid input file format.");
    }

    while(std::getline(file, line))
    {
        if (line.empty())
            continue;
        
    }
}