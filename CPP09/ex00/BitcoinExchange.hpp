/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raalifa <raalifa@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 15:05:05 by raalifa           #+#    #+#             */
/*   Updated: 2026/07/30 15:05:05 by raalifa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> exchangeRates;
        std::string trim(const std::string &str);
        // double      getExchangeRate(const std::string &date);
        // bool        isValidDate(const std::string &date);
        // bool        isValidValue(const std::string &valueStr, double &value);
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange& operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void loadDatabase(const std::string &filename);
        void processInputFile(const std::string &inputFile);



};

#endif