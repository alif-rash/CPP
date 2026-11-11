/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:05:00 by raalifa           #+#    #+#             */
/*   Updated: 2026/11/11 11:27:10 by raalifa          ###   ########.fr       */
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
        this->exchangeRates = other.exchangeRates;
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
    if (filename.length() < 4 || (filename.substr(filename.length() - 4) != ".csv"))
    {
        throw std::runtime_error("Error: could not open file.");
    }
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string line;
    if(!std::getline(file, line) || trim(line) != "date,exchange_rate")
    {
        throw std::runtime_error("Error: could not open file.");
    }
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, commaPos));
        double value = std::strtod(line.substr(commaPos + 1).c_str(), NULL);
        exchangeRates[date] = value;
    }
    file.close();
}

bool BitcoinExchange::isValidDate(const std::string &date){
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.length(); i++){
        if(i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 1000 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return day <= 30;
    if (month == 2){
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        return day <= (isLeap ? 29 : 28);
    }
    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valStr, double &value){
    if (valStr.empty())
    {
        std::cout << "Error: bad input => " << valStr << std::endl;
        return false;
    }
    char *end;
    value = std::strtod(valStr.c_str(), &end);
    if (end == valStr.c_str())
    {
        std::cout << "Error: bad input => " << valStr << std::endl;
        return false;
    }
    while (*end){
        if (!std::isspace(*end))
        {
            std::cout << "Error: bad input => " << valStr << std::endl;
            return false;
        }
        end++;
    }
    if (value < 0 || (value == 0.0 && valStr.find('-') != std::string::npos)){
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value > 1000){
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

double BitcoinExchange::getExchangeRate(const std::string &date){
    std::map<std::string, double>::iterator it = exchangeRates.upper_bound(date);
    if (it == exchangeRates.begin())
        throw std::runtime_error("Error: bad input => " + date);
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("Error: could not open file.");
    }
    std::string line;
    if (!std::getline(file, line))
    {
        return;
    }
    if (trim(line) != "date | value")
    {
        file.clear();
        file.seekg(0, std::ios::beg);
    }

    while(std::getline(file, line))
    {
        if (line.empty())
            continue;
        
        size_t pipePos = line.find('|');
        if (pipePos == std::string::npos || line.find('|', pipePos + 1) != std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string date = trim(line.substr(0, pipePos));
        std::string valStr = trim(line.substr(pipePos + 1));
        if (date.empty() || !isValidDate(date))
        {
            std::cout << "Error: bad input => " << (date.empty() ? line : date) << std::endl;
            continue;
        }
        if (valStr.empty())
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        double value;
        if (!isValidValue(valStr, value))
        {
            continue;
        }
        try 
        {
            double rate = getExchangeRate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }       
        catch (std::exception &e) 
        {
            std::cout << e.what() << std::endl;
        }
    }
}

